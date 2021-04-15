/**
    Project     : Composite Pattern Example

    Authors     : Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides
**/

///////////////////////////////////////////ICOMPONENT-INTERFACE///////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IListable {
    public:
        virtual ~IListable(){};
        virtual void list(int depth) = 0;
};

class IComposableOfListable {
    public:
        virtual ~IComposableOfListable(){};
        virtual void add(IListable *component) = 0;
        virtual void remove(IListable *component) = 0;
};

/////////////////////////////////////////////COMPOSITE///////////////////////////////////////////////////////
class Folder : public IComposableOfListable, public IListable {
    private:
        string m_nodeName;
        vector<IListable*> m_children;

    public:
       Folder(string nodeName) {
           m_nodeName = nodeName;
       }

        virtual ~Folder(){}

        void list(int depth) {//operation
            string newStr(depth, '-');
            cout << newStr << m_nodeName << " depth: " << depth << endl;
            for(IListable* currentChild : m_children)
                if(currentChild != 0)
                    currentChild->list(depth + 1);
        }

        void add(IListable* component) {
            m_children.push_back(component);
        }

        void remove(IListable* component) {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////LEAF////////////////////////////////////////////////////////
class File : public IListable {
    private:
        string m_nodeName;
        vector<IListable*> m_children;

    public:
        File(string nodeName) {
            m_nodeName = nodeName;
        }

        virtual ~File(){}

        void list(int depth) {//operation
            string newStr(depth, '-');
            cout << newStr << m_nodeName << " depth: " << depth << endl;
        }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////
int main()
{
    Folder* folder_01 = new Folder("folder_01");

    Folder* folder_02 = new Folder("folder_02");
    folder_01->add(folder_02);

    File* fileA = new File("File A");
    File* fileB = new File("File B");

    Folder* folder_03 = new Folder("folder_03");
    folder_03->add(fileB);
    folder_03->add(new File("file C"));
    folder_02->add(folder_03);
    folder_02->add(fileA);

    folder_01->list(1);

    delete folder_03;
    delete folder_02;
    delete folder_01;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
