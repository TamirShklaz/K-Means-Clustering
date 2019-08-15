//
// Created by tamir on 2019/08/15.
//

#include "Cluster.h"

Cluster::Cluster(const Point &centroid, const vector<int> &points) : centroid(centroid), points(points) {}

Cluster::Cluster() {
}

Cluster::Cluster(const Point &centroid) : centroid(centroid) {}
