#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex {
    private:
        int index;

    public:
        Vertex();
        Vertex(int index);
        int get_index();
        void set_index(int index);
};

#endif
