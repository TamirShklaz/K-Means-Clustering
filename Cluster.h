//
// Created by tamir on 2019/08/15.
//

#ifndef AS2_CLUSTER_H
#define AS2_CLUSTER_H
using namespace std;


#include <vector>
#include "Point.h"

class Cluster {
public:
    Point centroid;
    vector<int> points;

    Cluster(const Point &centroid, const vector<int> &points);

    Cluster(const Point &centroid);

    string getPoints() {
        string s = "";
        for (int p: points) {
            s += to_string(p + 1) + " ";
        }
        return s;
    }

    Cluster();
};


#endif //AS2_CLUSTER_H
