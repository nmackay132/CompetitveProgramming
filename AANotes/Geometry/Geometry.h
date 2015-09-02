#include <math.h>
#include <utility>

#define EPS 1.0e-9
#define PI acos(0.0)*2.0
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians
#define are_equal(a,b)fabs(a-b)<EPS

typedef pair<int, int> ii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }

//_____________________________________________________________________________


struct point_i{ // use when points are integers
	int x, y;
	point_i(){ x = y = 0; }
	point_i(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (point_i other) const {	// override less than operator
		if (x != other.x)		// useful for sorting
			return x < other.x;				// first criteria, by x-coordinate
		return y < other.y;					// second criteria, by y-coordinate
	}
	bool operator == (point_i other) const{
		return (x == other.x && y == other.y);
	}
};

struct point{ // use when points are doubles
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {	// override less than operator
		if (fabs(x - other.x) > EPS)		// useful for sorting
			return x < other.x;				// first criteria, by x-coordinate
		return y < other.y;					// second criteria, by y-coordinate
	}
	bool operator == (point other) const{
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

// calc distance between two points
double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

// rotate p by theta degress CCW with respect to origin
point rotate(point p, double theta){
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

// coefficiants of ax + by + c = 0
struct line{
	double a, b, c;
	line(){
		a = b = c = 0.0;
	}
	line(point p1, point p2){
		if (are_equal(p1.x, p2.x)){
			a = 1.0;
			b = 0.0;
			c = -p1.x;
		}
		else{
			a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
			b = 1.0;
			c = -(double)(p1.x*a) - p1.y;
		}
	}
};

// the answer is stored in the third parameter by reference
void pointsToLine(point p1, point p2, line &l){
	if (fabs(p1.x - p2.x) < EPS){
		l.a = 1.0;  l.b = 0.0;  l.c = -p1.x;
	}
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

// returns if lines are parallel
bool areParallel(line l1, line l2){
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

// returns if lines are the same
bool areSame(line l1, line l2){
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns if lines intersect and stores byref point of intersection
bool areIntersect(line l1, line l2, point &p){
	if (areParallel(l1, l2)) return false; // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return true;
}


//****VECTORS****

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

//convert 2 points to vector a->b
vec toVec(point a, point b){ 
	return vec(b.x - a.x, b.y - a.y);
}

//scale a vector v by s
vec scale(vec v, double s){
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b){
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v){
	return v.x * v.x + v.y * v.y;
}

// returns the distance from p to the line defined by 2 points a & b
// a & b must be different
// the closest point is stored in the 4th parameter (by reference)
double distToLine(point p, point a, point b, point &c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

// returns the distance from p to the line segment ab defined by two points a and b
// ok if a == b
// the closest point is stored in the 4th parameter by reference
double distToLineSegment(point p, point a, point b, point &c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b);
	}
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

// returns angle aob in radians
double angle(point a, point o, point b) {
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// returns cross product of vec a and vec b
double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

// Counter Clockwise Test
// returns true if point r is on the left side of line pq
//note: to accept collinear points, we have to change the "> 0" to ">=0"
bool ccw(point p, point q, point r){
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}


//****CIRCLES****

// returns int value 0,1,2 if point is inside, on, or outside circle
int insideCircle(point_i p, point_i c, int r){
	int dx = p.x - c.x, dy = p.y - c.y;
	int Euc = dx * dx + dy * dy, rSq = r * r;
	return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; // inside=0/border=1/outside=2
}

// Given 2 points on the circle (p1 and p2) and radius r, returns byref the
// location of the two possible centers (c1 and c2);
bool circle2PtsRad(point p1, point p2, double r, point &c1, point &c2){
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	double det = r*r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c1.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c1.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	c2.x = (p1.x + p2.x) * 0.5 + (p2.y - p1.y) * h;
	c2.y = (p1.y + p2.y) * 0.5 + (p1.x - p2.x) * h;
	return true;
}


//****TRIANGLES AND CIRCLES****

// returns area of triangle given lengths of three sides
double area(double ab, double bc, double ca){ //uses Heron's formula
	double s = (ab + bc + ca)/2;
	return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}

// returns radius of inscribed circle in triangle abc given side lengths
double rInCircle(double ab, double bc, double ca){
	return area(ab, bc, ca) / (0.5*(ab + bc + ca));
}

// returns radius of inscribed circle in triangle abc given three vertices
double rInCircle(point a, point b, point c){
	double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
	return area(ab, bc, ca) / (0.5*(ab + bc + ca));
}

// returns 1 if there is an circle inscribed in the triangle, returns 0 otherwise
// finds ctr and radius of circle byref
int inCircle(point p1, point p2, point p3, point &ctr, double &r){
	r = rInCircle(p1, p2, p3);
	if (fabs(r) < EPS) return 0;	// no inCircle center

	line l1, l2;					// will compute these two angle bisectors
	double ratio = dist(p1, p2) / dist(p1, p3);
	point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
	pointsToLine(p1, p, l1);

	ratio = dist(p2, p1) / dist(p2, p3);
	p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
	pointsToLine(p2, p, l2);

	areIntersect(l1, l2, ctr);		// get their intersection point
	return 1;
}

// returns radius of circumscribed circle around triangle abc given side lengths
double rCircumCircle(double ab, double bc, double ca){
	return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

// returns radius of circumscribed circle around triangle abc given three vertices
// (returns radius of given 3 points
double rCircumCircle(point a, point b, point c){
	double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
	return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
