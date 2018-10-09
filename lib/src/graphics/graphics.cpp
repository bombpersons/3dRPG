#include <3drpg/graphics/graphics.hpp>
#include <3drpg/graphics/drawable/drawable.hpp>

#include <string>
#include <map>

namespace rpg {
  namespace graphics_internal {
    class ModelLoader {
    public:
      static irr::scene::IAnimatedMesh* loadAnimatedModel(irr::scene::ISceneManager* smgr, const char* file) {
        // See if we've already got this one..
        auto found = s_meshes.find(file);
        if (found == s_meshes.end()) {
          irr::scene::IAnimatedMesh* mesh = smgr->getMesh(file);
          if (!mesh) return nullptr;

          MeshReference ref;
          ref.mesh = mesh;
          ref.ref = 0;

          s_meshes[file] = ref;
          found = s_meshes.find(file);
        }

        // Grab it, inc the ref and return.
        found->second.ref++;
        return found->second.mesh;
      }

      static void unloadAnimatedModel(irr::scene::ISceneManager* smgr, const char* file) {
        // Find the mesh.
        auto found = s_meshes.find(file);
        if (found == s_meshes.end())
          return; // not loaded anyway.

        found->second.ref--;
        if (found->second.ref == 0) {
          // Unload the mesh.
          delete found->second.mesh;
          s_meshes.erase(found);
        }
      }

    private:
      struct MeshReference {
        irr::scene::IAnimatedMesh* mesh;
        unsigned int ref;
      };
      static std::map<std::string, MeshReference> s_meshes;
    };
    std::map<std::string, ModelLoader::MeshReference> ModelLoader::s_meshes;

    class GraphicsDrawable : public rpg::Drawable {
    public:
      GraphicsDrawable(irr::scene::ISceneManager* smgr) : m_smgr(smgr) {
        m_modelNode = nullptr;
      }

      virtual ~GraphicsDrawable() {
      }

      bool loadModel(const char* file) override {
        if (!m_smgr) return false;
        if (m_modelPath == file) return true;

        // Unload the existing model if it exists..
        if (!m_modelPath.empty()) {
          ModelLoader::unloadAnimatedModel(m_smgr, m_modelPath.c_str());
        }

        // Load the new one.
        irr::scene::IAnimatedMesh* mesh = ModelLoader::loadAnimatedModel(m_smgr, file);
        if (mesh) {
          m_modelNode = m_smgr->addAnimatedMeshSceneNode(mesh);
          m_modelPath = file;
        }

        return m_modelNode != nullptr;
      }
      void setTransform(const glm::mat4& mat) override {
        // TODO
      }
      void setAnimation(const char* name) override {
        // TODO
      }
      void setAnimationPosition(float pos) override {
        // TODO
      }

    private:
      irr::scene::ISceneManager* m_smgr;

      // Irrlicht meshes and whatnot.
      std::string m_modelPath;
      irr::scene::IAnimatedMeshSceneNode* m_modelNode;
    };
  }

  void Graphics::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<Graphics>(), "Graphics");

    // Add some functions here...
    chai.add(chaiscript::fun(&Graphics::useNormalCamera), "useNormalCamera");
    chai.add(chaiscript::fun(&Graphics::useDebugCamera), "useDebugCamera");
  }

  Graphics::Graphics(irr::IrrlichtDevice* device) {
    m_device = device;
    m_driver = m_device->getVideoDriver();
    m_smgr = m_device->getSceneManager();
    m_guienv = m_device->getGUIEnvironment();

    m_camera = nullptr;
    useNormalCamera();
  }

  Graphics::~Graphics() {
    // Window handles the device and what not, so don't delete anything here.
  }

  // Create a thing to draw.
  Drawable* Graphics::createDrawable() {
    return new graphics_internal::GraphicsDrawable(m_smgr);
  }
  void Graphics::deleteDrawable(Drawable* drawable) {
    delete drawable;
  }

  void Graphics::useNormalCamera() {
    if (m_camera) {
      m_camera->remove();
      delete m_camera;
    }
  }

  void Graphics::useDebugCamera() {
    if (m_camera) {
      m_camera->remove();
      delete m_camera;
    }

    m_smgr->addCameraSceneNodeFPS();
  }

  void Graphics::draw() {
    m_driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
    m_smgr->drawAll();
    m_guienv->drawAll();
    m_driver->endScene();
  }

}
