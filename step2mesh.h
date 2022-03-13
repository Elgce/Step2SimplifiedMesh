
namespace step2mesh {

struct New_Mesh {
    New_Mesh() = delete;
    New_Mesh(const New_Mesh &) = delete;
};

struct MeshStats {
    int num_vertices;
    int num_faces;
};

struct MeshPoint3d {
    double x;
    double y;
    double z;
};

struct MeshIndexedTriangle {
    int id[3];
};


extern "C" {

New_Mesh *mesh_from_step(const char *str);

New_Mesh *mesh_read_step(const char *str);

void mesh_free(New_Mesh *ptr_mesh);

void mesh_get_stats(const New_Mesh *ptr_mesh, MeshStats *ptr_stat);

void mesh_export(const New_Mesh *ptr_mesh, MeshPoint3d *ptr_verts, MeshIndexedTriangle *ptr_faces);

int mesh_save_obj(const New_Mesh *ptr_mesh, const char *filename);

int mesh_save_stl(const New_Mesh *ptr_mesh, const char *filename);

} // extern "C"

} // namespace step2mesh
