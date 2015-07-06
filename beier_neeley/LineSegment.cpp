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
			LineSegment(const cv::Point2d& p_ = cv::Point2d(), const cv::Point2d& q_ = cv::Point2d()) : p(p_), q(q_)
			{
				init_vectors();
			}

			LineSegment(double x1, double y1, double x2, double y2) : LineSegment(cv::Point2d(x1,y1), cv::Point2d(x2, y2)) {}
			

			static LineSegment interpolate(const LineSegment& l1, const LineSegment& l2, double t = 0.5)
			{
				cv::Point2d pp = (1 - t) * l1.p + t * l2.p;
				cv::Point2d qq = (1 - t) * l1.q + t * l2.q;
				return LineSegment(pp, qq);
			}

			void init_vectors()
			{
				pq = q - p;
				length = sqrt(pq.ddot(pq));
				pq /= length;
				perp = cv::Point2d(pq.y, -pq.x);
			}

			cv::Point2d p, q;
			double length;
			cv::Point2d pq, perp;
	};

	struct LinePair
	{
		public:
			LinePair(LineSegment l1_ = LineSegment(), LineSegment l2_ = LineSegment()) : l1(l1_), l2(l2_) { }
			LineSegment l1, l2;

			friend std::ostream& operator<< (std::ostream &out, LinePair& lp)
			{
				out << "[(" << lp.l1.p.x << ", " << lp.l1.p.y << ") -> (" << lp.l1.q.x << ", " << lp.l1.q.y << ")] "
					<< "[(" << lp.l2.p.x << ", " << lp.l2.p.y << ") -> (" << lp.l2.q.x << ", " << lp.l2.q.y << ")]";

				return out;
			}
	};

	class LinePairs
	{
		public:
			LinePairs() : line_pairs() {}
			LinePairs(char* filename) : LinePairs()
			{
				load(filename);
			}
			
			void load(char* filename)
			{
				line_pairs.clear();
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

					LinePair lp(LineSegment(p1, q1), LineSegment(p2, q2));
					line_pairs.push_back(lp);
				}
			}

			void add_line(const LinePair& lp)
			{
				line_pairs.push_back(lp);
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