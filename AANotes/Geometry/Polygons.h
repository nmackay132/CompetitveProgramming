
//*****POLYGONS*****
// returns the perimeter of the polygon
double perimeter(const vector<point> &P) {
	double result = 0.0;
	for (int i = 0; i < (int)P.size() - 1; i++) { //remember P[0] = P[n-1]
		result += dist(P[i], P[i + 1]);
	}
	return result;
}

// returns the area of the polygon, which is half the determinant
double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size() - 1; i++) {
		x1 = P[i].x; x2 = P[i].x;
		y1 = P[i].y; y2 = P[i + 1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}

// returns true if the polygon is convex
bool isConvex(const vector<point> &P) {
	int sz = (int)P.size();
	if (sz <= 3) return false;
	bool isLeft = ccw(P[0], P[1], P[2]);
	for (int i = 0; i < sz - 1; i++) {
		if (ccw(P[i], P[i + 1], P[(i + 2) == sz ? 1 : i + 2] != isLeft)) {
			return false;
		}
		return true;
	}
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
	if ((int)P.size() == 0) return false;
	double sum = 0;
	for (int i = 0; i < (int)P.size(); i++) {
		if (ccw(pt, P[i], P[i + 1])) {
			sum += angle(P[i], pt, P[i + 1]);
		}
		else {
			sum -= angle(P[i], pt, P[i + 1]);
		}
	}
	return fabs(fabs(sum) - 2 * PI) < EPS;
}

// line segment p-q intersect line A-B (belongs with next method)
point lineIntersectSeg(point p, point q, point A, point b) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a*p.x + b*p.y + c);
	double v = fabs(a*q.x + b*q.y + c);
	return point((p.x*v + q.x*u) / (u + v), (p.y*v + q.y*u) / (u + v));
}

// cuts polgon Q along the line formed by point a to point b, 
// returns polygon on left side of line, swap points a and b to return polygon on the right side
// note: the last point must be the same as the first point
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++) {
		double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size() - 1) left2 = cross(toVec(a, b), toVec(a, Q[i + 1]));
		if (left1 > -EPS) P.push_back(Q[i]);			// Q[i] is on the left of ab
		if (left1 * left2 < -EPS)				// edge (Q[i], Q[i+1]) cross line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front());					// make P's first point = P's last point
	return P;
}

// CONVEX HULL

point pivot(0, 0);
bool angleCmp(point a, point b) {		// angle sorting method
	if (collinear(pivot, a, b))					// special case
		return dist(pivot, a) < dist(pivot, b);	// check which one is closer
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;		// compare two angles
}

// finding Convex Hull of set of points
vector<point> CH(vector<point> P) {			// the content of P may be reshuffled
	int i, j, n = (int)P.size();
	if (n <= 3) {
		if (!(P[0] == P[n - 1])) P.push_back(P[0]);		// safeguard from corner case
		return P;
	}

	// first, find P0 = point with lowest Y and if tie: rightmost X
	int P0 = 0;
	for (int i = 1; i < n; i++) {
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
	}

	point temp = P[0]; P[0] = P[P0]; P[P0] = temp;		// swap P[P0] with P[0]

	// second, sort point by angle w.r.t. pivot P0
	pivot = P[0];									// use this global variable as reference
	sort(++P.begin(), P.end(), angleCmp);			// we do not sort P[0]

	//third, the ccw tests
	vector<point> S;
	S.push_back(P[n - 1]); S.push_back(P[0]); S.push_back(P[1]);	// initial S
	i = 2;											// then we check the rest
	while (i < n) {
		j = (int)S.size() - 1;
		if (ccw(S[j - 1], S[j], P[i])) S.push_back(P[i++]);		// left turn , accept
		else S.pop_back();			// or pop the top of S until we have a left turn
	}
	return S;
}