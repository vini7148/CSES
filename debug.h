#ifdef DEBUG
#  define D(x) (x);
#else
#  define D(x) do{}while(0);
#endif // DEBUG

#ifdef UNITTEST
#  include <UnitTest++/UnitTest++.h>
#  define U(x) (x); // same concept as D(x) macro.
#  define N(x) do{}while(0);
#else
#  define U(x) do{}while(0);
#  define N(x) (x); // N(x) macro performs the opposite of U(x)
#endif

struct Component; // fwd decls
typedef std::list<Component> compList;

// represents a node in the graph. Components group GNs
// into manageable chunks (which turn into matrices which is why we want
// graph component partitioning: to minimize matrix size)
struct GraphNode {
    U(Component* comp;) // this guy only exists in unit test build
    std::vector<int> adj; // neighbor list: These are indices
    // into the node_list buffer (used to be GN*)
    uint64_t h_i; // heap index value
    U(int helper;) // dangling variable for search algo to use (comp node idx)
    // todo: use a more space-efficient neighbor container?
    U(GraphNode(uint64_t i, Component* c, int first_edge):)
    N(GraphNode(uint64_t i, int first_edge):)
        h_i(i) {
        U(comp = c;)
        U(helper = -1;)
        adj.push_back(first_edge);
    }
    U(GraphNode(uint64_t i, Component* c):)
    N(GraphNode(uint64_t i):)
        h_i(i)
    {
        U(comp=c;)
        U(helper=-1;)
    }
    inline void add(int n) {
        adj.push_back(n);
    }
};

// A component is a ugraph component which represents a set of rows that
// can potentially be assembled into one wall.
struct Component {
#ifdef UNITTEST // is an actual real struct only when testing
    int one_node; // any node! idx in node_list (used to be GN*)
    Component* actual_component;
    compList::iterator graph_components_iterator_for_myself; // must be init'd
    // actual component refers to how merging causes a tree of comps to be
    // made. This allows the determination of which component a particular
    // given node belongs to a log-time operation rather than a linear one.

    D(int count;) // how many nodes I (should) have

    Component(): one_node(-1), actual_component(NULL) {
        D(count = 0;)
    }
#endif
};

#ifdef DEBUG
// a global pointer to the node list that makes it a little
// easier to reference it
std::vector<GraphNode> *node_list_ptr;

#  ifdef UNITTEST
std::ostream& operator<<(std::ostream& os, const Component& c) {
    os << "<s=" << c.count << ": 1_n=" << node_list_ptr->at(c.one_node).h_i;
    if (c.actual_component) {
        os << " ref=[" << *c.actual_component << "]";
    }
    os << ">";
    return os;
}
#  endif
#endif