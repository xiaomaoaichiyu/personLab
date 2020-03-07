#include "../person_lab/person_lab.h"

using namespace std;

bool getCross(Line l1, Line l2, Point* res) {
	double a1 = l1.y1 - l1.y2;
	double b1 = l1.x2 - l1.x1;
	double c1 = l1.x1 * l1.y2 - l1.x2 * l1.y1;

	double a2 = l2.y1 - l2.y2;
	double b2 = l2.x2 - l2.x1;
	double c2 = l2.x1 * l2.y2 - l2.x2 * l2.y1;

	double D = a1 * b2 - a2 * b1;
	if (D == 0) {
		return false;
	}
	res->setX((b1 * c2 - b2 * c1) / D);
	res->setY((a2 * c1 - a1 * c2) / D);
	return true;
}

int getAllIntersrc(vector<Line> lines) {
	set<Point> points;

	for (int i = 0; i < lines.size() - 1; i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			Point p;
			if (getCross(lines.at(i), lines.at(j), &p)) {
				points.insert(p);
			}
		}
	}

	return points.size();
}


int main(int argc, char** argv)
{
	string inFileName = argv[2];
	string outFileName = argv[4];
	ifstream fileIn("input.txt", ios::in);
	ofstream fileOut(outFileName, ios::out);

	if (!fileIn) {
		cout << "input file open Error!!" << endl;
		return 0;
	}

	if (!fileOut) {
		cout << "output file open Error!!" << endl;
		return 0;
	}

	int lineNum = 0;
	vector<Line> lines;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char mark;
	fileIn >> lineNum;
	for (int i = 0; i < lineNum; i++) {
		fileIn >> mark;
		if (mark != 'L') {
			cout << "wrong! should be 'L'!" << endl;
		}
		fileIn >> x1 >> y1 >> x2 >> y2;
		Line line(x1, y1, x2, y2);
		lines.push_back(line);
	}
	
	//get the intersection num of all lines
	int res = getAllIntersrc(lines);


	fileOut << res << endl;
	//cout << res << endl;
	return 0;
}


