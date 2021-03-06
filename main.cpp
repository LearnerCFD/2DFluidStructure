#include <iostream>
//#include <Eigen/Dense>
//using Eigen::MatrixXd;
//#include"Segment_Hierarchy.h"
//#include"Intersector.h"
#include "MatrixVec.h"
using namespace std;
#include <vector>
#include "Vector2D.h"
#include "Array.h"
#include<math.h>

void MatrixVec_Test(){
    int m = 4, n = 5;

    const int dim=3;
    MatrixVec<dim> v1(m,n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < dim; k++)
                v1(i,j)[k] = i*n+j;

    MatrixVec<dim> v2(m,n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < dim; k++)
                v2(i,j)[k] = k;

    MatrixVec<dim> v3(m,n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < dim; k++)
                v3(i,j)[k] = 1;



    MatrixVec<dim> v4(m,n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < dim; k++)
                v4(i,j)[k] = 0;

    v4 = 2.0*v3 + v3 - v3 + v3 - v3 +2*v3;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
                std::cout << "(" <<i <<"," << j << ")" << v4(i,j)[0] <<" " << v4(i,j)[1] << " " << v4(i,j)[2] <<std::endl;




}
/*
void Segment_Hierarchy_Test() {
    const double PI = 3.1415926535898;
    std::cout << "Segment_Hierarchy_Test" << std::endl;

    int segmentNumber = 4;
    Array<Vector2D<double>> points(segmentNumber);
    Array<Vector2D<int>> edgeSet(segmentNumber);
    for(int i = 0; i < segmentNumber; i++){
        points[i] = Vector2D<double>(cos(i*2.0*PI/segmentNumber),sin(i*2.0*PI/segmentNumber));
        edgeSet[i] = Vector2D<int>(i, (i+1)%segmentNumber);
    }

    Segment_Hierarchy segmentHierarchy(points,edgeSet);
    segmentHierarchy.Print_Info();
}
*/

/*
void KD_Tree_Test() {
    std::cout << "Start KD Tree Test" << std::endl;

    int segmentNumber = 7;
    Array<Vector2D<double>> centroids(segmentNumber);

    centroids[0] = Vector2D<double>(2.0, 3.0);
    centroids[1] = Vector2D<double>(4.0, 7.0);
    centroids[2] = Vector2D<double>(5.0, 4.0);
    centroids[3] = Vector2D<double>(7.0, 2.0);
    centroids[4] = Vector2D<double>(8.0, 1.0);
    centroids[5] = Vector2D<double>(9.0, 3.0);
    centroids[6] = Vector2D<double>(9.0, 6.0);
    KD_Tree kdTree;

    kdTree.Create_KD_Tree(centroids);
    kdTree.Print_Tree_Info();
}
 */

/*
void Intersector_Test(){
    const double PI = 3.1415926535898;
    int xFluidNum = 5,yFluidNum = xFluidNum;
    double L = 2.0;
    double thickness = 1.0e-8;
    Vector2D<double> *Xf = new Vector2D<double>[xFluidNum*yFluidNum];
    for (int i = 0 ; i < yFluidNum; i++)
        for(int j = 0; j < xFluidNum; j++)
            Xf[i*xFluidNum + j] = Vector2D<double>(2*L*j/(xFluidNum-1.0) - L, 2*L*i/(yFluidNum-1) - L);

    int numEdge = 4;
    int numXs = numEdge;
    double Xs[2*numEdge];
    int edge[2*numEdge];
    for(int i = 0; i < numEdge; i++) {
        Xs[2 * i] = cos(i * 2.0 * PI / numEdge);
        Xs[2 * i + 1] = sin(i * 2.0 * PI / numEdge);
        edge[2 * i] = i;
        edge[2 * i + 1] = (i + 1) % numXs;
    }
    // parallel test
    {
        double a = 0.5, b = 1.0;
        Xs[0] = a;
        Xs[1] = b;
        Xs[2] = -a;
        Xs[3] = b;
        Xs[4] = -a;
        Xs[5] = -b;
        Xs[6] = a;
        Xs[7] = -b;
    }



    Intersector intersector(xFluidNum, yFluidNum,Xf, numXs, Xs, numEdge, edge, thickness);
    intersector.Print_Intersector_Info();

    {
        double a1 = -0.1, a2 = -0.3, b = 0.9;
        Xs[0] = a1;
        Xs[1] = b;
        Xs[2] = a2;
        Xs[3] = b;
        Xs[4] = a2;
        Xs[5] = -b;
        Xs[6] = a1;
        Xs[7] = -b;
    }
    intersector.Recompute(Xs, thickness);
    intersector.Print_Intersector_Info();

    }
*/
int main() {
    //KD_Tree_Test();
    //Segment_Hierarchy_Test();
    //Intersector_Test();
    MatrixVec_Test();



    return 0;
}
