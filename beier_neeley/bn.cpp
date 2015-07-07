#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "LineSegment.cpp"
#include "bn.h"
using namespace cv;
using namespace std;



void morph(const std::string& src_file, const std::string& dst_file, const bn::LinePairs& lines, const std::string& out_file, double frames, std::function<void(int)> prog_callback)
{
	Mat src, dst, mid1, mid2, out;
	Mat map_x1, map_y1, map_x2, map_y2;

	src = imread(src_file, 1);
	dst = imread(dst_file, 1);

	Size sz = src.size();

	mid1.create(sz, dst.type());
	mid2.create(sz, dst.type());
	out.create(sz, dst.type());

	map_x1.create(sz, CV_32FC1);
	map_y1.create(sz, CV_32FC1);
	map_x2.create(sz, CV_32FC1);
	map_y2.create(sz, CV_32FC1);

	if (!src.data || !dst.data)
	{
		std::cout << "Failed to load images." << endl;
		exit(-1);
	}

	int dot_pos = out_file.find_last_of('.');
	std::string filename = out_file.substr(0, dot_pos);
	std::string file_ext = out_file.substr(dot_pos);
	std::stringstream file_ss;
	
	for (int f = 0; f <= frames; ++f)
	{
		vector<bn::LineSegment> mids;
		double t = f / frames;

		for (auto itr = lines.line_pairs.begin(); itr != lines.line_pairs.end(); ++itr)
			mids.push_back( bn::LineSegment::interpolate(itr->l1, itr->l2, t) );

		for (int j = 0; j < out.rows; j++)
		{
			for (int i = 0; i < out.cols; i++)
			{
				Point2d dSum1, dSum2;
				double wSum = 0.0;
				auto mid_itr = mids.begin();

				for (auto itr = lines.line_pairs.begin();
					itr != lines.line_pairs.end(); ++itr, ++mid_itr)
				{
					Point2d X(i, j);
					Point2d XP = X - mid_itr->p;

					double u = XP.ddot(mid_itr->pq) / mid_itr->length;
					double v = XP.ddot(mid_itr->perp);

					double dist = bn_dist(X, XP, mid_itr->q, u, v);

					double weight = pow(mid_itr->length / (1 + dist), 2);
					wSum += weight;

					Point2d Xs1 = itr->l1.p + u * itr->l1.length * itr->l1.pq + v*itr->l1.perp;
					Point2d Xs2 = itr->l2.p + u * itr->l2.length * itr->l2.pq + v*itr->l2.perp;

					dSum1 += weight * Xs1;
					dSum2 += weight * Xs2;
				}
				dSum1 /= wSum;
				dSum2 /= wSum;

				map_x1.at<float>(j, i) = dSum1.x;
				map_y1.at<float>(j, i) = dSum1.y;
				map_x2.at<float>(j, i) = dSum2.x;
				map_y2.at<float>(j, i) = dSum2.y;
			}
		}

		cv::remap(src, mid1, map_x1, map_y1, CV_INTER_LINEAR, BORDER_REPLICATE);
		cv::remap(dst, mid2, map_x2, map_y2, CV_INTER_LINEAR, BORDER_REPLICATE);
		cv::addWeighted(mid1, 1 - t, mid2, t, 0.0, out);
		
		file_ss.str("");
		file_ss << filename << f << file_ext;
		cv::imwrite(file_ss.str(), out);
		std::cout << "\r" << f << "/" << frames;

		prog_callback(f);
	}
	
}