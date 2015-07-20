#ifndef PLUGINAPSSSMOOTHING
#define PLUGINAPSSSMOOTHING
#include <PluginCore/PluginInterface/MeshFilterInterface.h>

namespace GCL {

class OMesh;
namespace Plugins {
/**
 * @brief The APSSSmoothingPlugin class
 *       APSS Smoothing algorithm
 * @author Lihan Huang
 * @date 2015.7
 * @ref  APSS Smoothing
 */

class APSSSmoothingPlugin : public MeshFilterInterface
{
    Q_OBJECT
    GCL_MESH_PLUGIN_IID_EXPORTER(GCL_MESHFILTER_INTERFACE_IID)
    Q_INTERFACES(GCL::Plugins::MeshFilterInterface)
public:
    explicit APSSSmoothingPlugin();
    int getFilterType() const;
    void initParameters();
public slots:
    bool apply();
public:
    void APSSSmoothing(OMesh &mesh);


};
}}
#endif // PLUGINAPSSSMOOTHING

