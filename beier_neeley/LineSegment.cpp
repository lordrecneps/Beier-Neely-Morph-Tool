#ifndef BN_LINE_SEGMENT
#define BN_LINE_SEGMENT

#include <opencv2/core/core.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>

namespace bn
{
	struct LineSegment
	{
		public:
			LineSegment(const cv::Point2d& p_, const cv::Point2d& q_) : p(p_), q(q_)
			{
				pq = q - p;
				length = sqrt( pq.ddot(pq) );
				pq /= length;
				perp = cv::Point2d(pq.y, -pq.x);
			}

			static LineSegment interpolate(const LineSegment& l1, const LineSegment& l2, double t = 0.5)
			{
				cv::Point2d pp = (1 - t) * l1.p + t * l2.p;
				cv::Point2d qq = (1 - t) * l1.q + t * l2.q;
				return LineSegment(pp, qq);
			}

			cv::Point2d p, q;
			double length;
			cv::Point2d pq, perp;
	};

	struct LinePair
	{
		public:
			LinePair(LineSegment l1_, LineSegment l2_) : l1(l1_), l2(l2_) { }
			LineSegment l1, l2;
	};

	class LinePairs
	{
		public:
			LinePairs() : line_pairs() {}
			LinePairs(char* filename) : LinePairs()
			{
				std::ifstream file(filename);

				if (!file.is_open())
				{
					std::cout << "Failed to open line file." << std::endl;
					exit(-1);
				}

				int numLines;
				file >> numLines;

				for (int i = 0; i < numLines; ++i)
				{
					cv::Point2d p1, q1, p2, q2;
					file >> p1.x >> p1.y >> q1.x >> q1.y;
					file >> p2.x >> p2.y >> q2.x >> q2.y;

					LinePair lp(LineSegment(p1, q1), LineSegment(p2,q2));
					line_pairs.push_back(lp);
				}
			}

			void print()
			{
				for (auto itr = line_pairs.begin(); itr != line_pairs.end(); ++itr)
				{
					std::cout << itr->l1.p << " " << itr->l1.q << " " << itr->l2.p << " " << itr->l2.q << std::endl;
				}
			}

			std::vector<LinePair> line_pairs;
	};
}

#endif