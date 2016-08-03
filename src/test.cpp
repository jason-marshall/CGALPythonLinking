#include "test.hpp"

extern "C"{
#if 0
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
#endif
  int test2(int angle){

    const char* fname = "skull_2.9.inr";
    // Load image
    CGAL::Image_3 image;
    if(!image.read(fname)){
      std::cerr << "Error: Cannot read file " <<  fname << std::endl;
      return EXIT_FAILURE;
    }
    // Domain
    Mesh_domain domain(image, 2.9f, 0.f);
    // Mesh criteria
    int facet_angle=30;
    int facet_size=6;
    int facet_distance=2;
    int cell_radius_edge_ratio=3;
    int cell_size=8;
    Mesh_criteria criteria(facet_angle, facet_size, facet_distance,
			   cell_radius_edge_ratio, cell_size);
    // Meshing
    C3t3 c3t3 = CGAL::make_mesh_3<C3t3>(domain, criteria);
    // Output
    std::ofstream medit_file("out.mesh");
    c3t3.output_to_medit(medit_file);
    return 0;
  }

}
