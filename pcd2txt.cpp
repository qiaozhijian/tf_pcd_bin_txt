#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "selfString.h"

using namespace std;

void pcd2txt(string pathPcd,string pathTxt)
{
    std::cout << " points have started" << std::endl;
    ofstream fout(pathTxt,ios::trunc|ios::out|ios::in);
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);  //create the input cloud

    if (pcl::io::loadPCDFile<pcl::PointXYZI> (pathPcd, *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return ;
    }

    for (size_t i = 0; i < cloud->points.size (); ++i)
        fout << cloud->points[i].x << '\t' << cloud->points[i].y << '\t' << cloud->points[i].z <<endl;
    fout.close();
//   std::cout << "Saving as ascii..." <<std::endl;
//   pcl::io::savePCDFileASCII (outFile, *cloud);
    std::cout <<cloud->points.size ()<< " points have been saved" << std::endl;
}
int main (int argc, char** argv)
{
    string filenameIn=string(argv[1]);
    string filenameOut(filenameIn);
    replace_str(filenameOut,".pcd",".txt");

    string filename=zfill(filenameIn,6);

    pcd2txt(filenameIn,filenameOut);

    return (0);
}
