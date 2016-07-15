#include "test.hpp"

extern "C"{
FT sphere_function (Point_3 p) {
  const FT x2=p.x()*p.x(), y2=p.y()*p.y(), z2=p.z()*p.z();
  return x2+y2+z2-1;
}

int test(double angular_bound){
  Tr tr;            // 3D-Delaunay triangulation
  C2t3 c2t3 (tr);   // 2D-complex in 3D-Delaunay triangulation

  // defining the surface
  Surface_3 surface(sphere_function,             // pointer to function
                    Sphere_3(CGAL::ORIGIN, 2.)); // bounding sphere
  // Note that "2." above is the *squared* radius of the bounding sphere!

  // defining meshing criteria
  CGAL::Surface_mesh_default_criteria_3<Tr> criteria(angular_bound,  // angular bound
                                                     0.1,  // radius bound
                                                     0.1); // distance bound
  // meshing surface
  //CGAL::make_surface_mesh(c2t3, surface, criteria, CGAL::Non_manifold_tag());

  //std::cout << "Final number of points: " << tr.number_of_vertices() << "\n";
  int return_val = 5;//tr.number_of_vertices();
  return return_val;
}
}
