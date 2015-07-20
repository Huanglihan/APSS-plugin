#include "pluginapsssmoothing.h"

#include <Core/DataStructures/OMesh.h>
#include <Core/gclnamespace.h>
#include <Eigen/Sparse>
//#include <Utilities/OpenMeshAlgorithms/LeastSquareLaplacian/LS_LaplacianEigenSolver.h>
#include <Core/Utilities/ProgressTool.h>
//#include <Eigen/Eigen>
//using namespace Eigen;

namespace GCL { namespace Plugins {

APSSSmoothingPlugin::APSSSmoothingPlugin()
{
    this->setObjectName("APSSSmoothing");
    initParameters();
}

int APSSSmoothingPlugin::getFilterType() const
{
    return  MeshFilterInterface::FILTER_SMOOTHING;
}

void APSSSmoothingPlugin::initParameters()
{
    RichParameters& paras = this->Parameters();

    paras.addParameter("steps",(int)3,tr("Smoothing steps"),tr("The number of the times that the whole algorithm is iterated"));
//    // 3: 添加一个StringList型参数
//    QStringList strlist;
//    strlist.push_back(tr("Local"));
//    strlist.push_back(tr("Global"));
//    paras.addParameter("Type",strlist,0,tr("Type"),tr("Local or Global Laplacian smoothing"));
//    // 4: 添加三个bool型参数
//    paras.addParameter("1D_Boudary",true,tr("1D Boundary Smooth"),tr("..."));
//    paras.addParameter("ctg_weight",false,tr("Cotangent weighting"),tr("..."));
//    paras.addParameter("only_selected",false,tr("Affect only selected surface"),tr("..."));
//    // 5: 添加一个double型参数
//    paras.addParameter("steplength",(double)0.2,tr("Step Length"),
//                       tr("Step length for each iteration"));

    paras.setName("APSS Smoothing");
    paras.setLabel(tr("APSS Smoothing"));
    paras.setIntroduction(tr("APSS Smoothing algorithms: "));
}

bool APSSSmoothingPlugin::apply()
{
    if(!this->getMesh()) return false;
    OMesh& mesh = *this->getMesh();
    RichParameters& paras = this->Parameters();
//    int type  = paras.getListIndex("Type");
    int step = paras.getValueInt("steps");
//    double steplength = paras.getValueDouble("steplength");
    if(step < 0) step = 0;
    if(step > 100) step = 100;
    while(step--)
    {
        APSSSmoothing(mesh);
    }
    mesh.update_normals();
    updateMesh(Geometry_Dirty);
    return true;
}

void APSSSmoothingPlugin::APSSSmoothing(OMesh &mesh)
{

}


}}

