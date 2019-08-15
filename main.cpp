#include <iostream>
#include <vector>
#include <fstream>
#include "Point.h"
#include "Cluster.h"

using namespace std;
vector<Point> points{{2, 10},
                     {2, 5},
                     {8, 4},
                     {5, 8},
                     {7, 5},
                     {6, 4},
                     {1, 2},
                     {4, 9}};


vector<Cluster> clusters{{points[0]},
                         {points[3]},
                         {points[6]}};

void populateClusters() {
    for (int i = 0; i < clusters.size(); i++) {
        clusters[i].points.clear();
    }
    for (int p = 0; p < points.size(); ++p) {
        double smallestDistance = clusters[0].centroid.getDistance(points[p]);
        int clusterToJoin = 0;
        for (int i = 1; i < clusters.size(); i++) {
            double distance = clusters[i].centroid.getDistance(points[p]);
            if (distance < smallestDistance) {
                smallestDistance = distance;
                clusterToJoin = i;
            }
        }
        clusters[clusterToJoin].points.push_back(p);
    }
}

Point calculateCentroid(Cluster &c) {

    double xSum, ySum = 0;
    for (int p : c.points) {
        xSum += points[p].getX();
        ySum += points[p].getY();
    }
    double x = xSum / c.points.size();
    double y = ySum / c.points.size();
    Point newCentroid(x, y);
    return newCentroid;

};

int main() {
    bool converge;
    int iteration = 1;
    ofstream outFile;
    outFile.open("out.txt");
    do {
        converge = true;
        populateClusters();
        cout << "Iteration " << iteration << endl;
        outFile << "Iteration " << iteration << endl;

        for (int c = 0; c < clusters.size(); c++) {
            Point centroid = calculateCentroid(clusters[c]);
            if (centroid != clusters[c].centroid) {
                converge = false;
                clusters[c].centroid = centroid;
            }
            cout << "Cluster " << (c + 1) << ": " << clusters[c].getPoints() << endl;
            cout << "Centroid " << clusters[c].centroid << endl;
            outFile << "Cluster " << (c + 1) << ": " << clusters[c].getPoints() << endl;
            outFile << "Centroid " << clusters[c].centroid << endl;
        }
        ++iteration;
        cout << "\n\n\n";
        outFile << "\n\n\n";

    } while (!converge);
    outFile.close();
    return 0;
}