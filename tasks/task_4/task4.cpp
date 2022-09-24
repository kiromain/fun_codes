#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Tree
{
private:
     std::string name;
     std::vector<std::shared_ptr<Tree>> children;
public:
     Tree(const std::string &name):name(name) { }

     std::shared_ptr<Tree> AddSub(const std::string &name)
     {
          std::shared_ptr<Tree> node=std::make_shared<Tree>(name);
          children.push_back(node);
          return node;
     }
     void print(int nest)const
     {
          std::cout<<std::string(nest,'\t')<<name<<std::endl;
          ++nest;
          for(const std::shared_ptr<Tree> node:children) node->print(nest);
     }
     int GetSubCount()
     {
          int countsub=0;
          for(const std::shared_ptr<Tree> node:children) countsub++;
          return countsub;
     }
     void GetAllSubCount(int s,int e)const
     {
          int count1[7];
          std::vector<int>::iterator u;
          int get=0; // getallsubcount
          for(u=children[s].begin();u!=children[s].end();u++){
               if(*u==e) continue;
               GetAllSubCount(*u,s);
               count1[s]+=count1[*u];
          }
          std::cout<<count1[0]<<std::endl;

     }
     void Del(int nest) const
     {

     }
};

int main()
{
     std::shared_ptr<Tree> root=std::make_shared<Tree>("tree name");
     std::shared_ptr<Tree> galaz1 = root->AddSub("galaz 1");
     std::shared_ptr<Tree> galaz2 = root->AddSub("galaz 2");
     std::shared_ptr<Tree> galaz3 = root->AddSub("galaz 3");
     std::shared_ptr<Tree> galaz1_1 = galaz1->AddSub("galaz 1.1");
     std::shared_ptr<Tree> galaz2_1 = galaz2->AddSub("galaz 2.1");
     std::shared_ptr<Tree> galaz2_2 = galaz2->AddSub("galaz 2.2");
     std::shared_ptr<Tree> galaz2_1_2 = galaz2_1->AddSub("galaz 2.1.2");
     root->print(0);

     uint32_t rootChildrenCnt = root->GetSubCount();
     uint32_t galaz1childrenCount = galaz1->GetSubCount();
     uint32_t countOfAllChildren = root->GetAllSubCount(1,0);
     std::cout<<"root children: "<<rootChildrenCnt<<std::endl;
     std::cout<<"galaz1 children: "<<galaz1childrenCount<<std::endl;
     std::cout<<"countOfAllChildren: "<<countOfAllChildren<<std::endl;

     root->Del(1);
/*
     uint32 rootChildrenCnt = root->GetSubCount(); // result shall be 3
     uint32 galaz1childrenCount = galaz1->GetSubCount(); // result shall be 1
     uint32 countOfAllChildren = root->GetAllSubCount();  // result shall be 7 (recursive children counting)

     root->Del(1); // will remove galaz_2 with all it's children (recursive), so in a result only galaz_1 and galaz_3 will stay

     uint32 rootChildrenCnt _v2 = root->GetSubCount(); // result shall be 2
     uint32 countOfAllChildren _v2 = root->GetAllSubCount(); // result shall be 3 (recursive children counting)

     delete(root); // deleting root shall remove all children (recursive) and clean memory
*/
     return 0;
}
