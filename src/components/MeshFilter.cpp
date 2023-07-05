#include "pd-engine/components/MeshFilter.h"

MeshFilter::MeshFilter(Filter type){
  switch(type){
    case Cube:
      for(float i : Cube::verts) { verts.push_back(i); }
      for(unsigned int i : Cube::indices){ indices.push_back(i); }
      count = Cube::count;
  }
};

std::vector<float> MeshFilter::getVerts(){
  return verts;
};

std::vector<unsigned int> MeshFilter::getIndices(){
  return indices;
};

unsigned int MeshFilter::getCount(){
  return count;
}
