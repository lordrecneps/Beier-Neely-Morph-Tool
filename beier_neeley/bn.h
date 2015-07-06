#ifndef BEIER_NEELEY_H
#define BEIER_NEELEY_H

#include <string>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void morph(char* src_file, char* dst_file, char* line_file, std::string out_file);

inline double bn_dist(const cv::Point2d& X, const cv::Point2d& XP, const cv::Point2d& Q, double u, double v)
{
	if (u < 0)
		return sqrt(XP.ddot(XP));

	if (u > 1)
	{
		cv::Point2d XQ = X - Q;
		return sqrt(XQ.ddot(XQ));
	}

	return abs(v);
}

#endif