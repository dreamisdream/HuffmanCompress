#include <iostream>
#include <vector>
#include <queue>

/*节点属性*/
template <class HW>
struct HuffTreeNode{
    HuffTreeNode(const HW &weight):huffWeight(weight),pLeft(nullptr),pRight(nullptr),pParent(nullptr){
    }
    HuffTreeNode<HW> *pLeft;
    HuffTreeNode<HW> *pRight;
    HuffTreeNode<HW> *pParent;
    HW huffWeight;
};
/*pleft->huffweight > pright->huffweight*/
template <class Hw>
struct Compare{
    bool operator()(HuffTreeNode<HW>* pleft,HuffTreeNode<HW>* pRight){
        if(pLeft->huffWeight > pRight->huffWeight){
            return true;
        }
        return false;
    }
/*huffmanTree */
template <class Hw>
class HuffmanTree{
    typedef HuffTreeNode<HW>  Node;
    typedef HuffTreeNode<HW>* pNode;
    private:
        pNode pRoot;
    public:
        HuffmanTree():pRoot(nullptr){
        }
     void CreateHuffmanTree(const std::vecotr<Hw> &Hweight,const HW& invalid){
         if(Hweight.empty()){
             std::cout<<"Empty Hweight"<<std::endl;
             return ;
         }
         /*创建二叉树森林,并放在小堆中*/
        std::priority_queue<pNode,std::vector<pNode>,Compare<HW>> prio_queue;
        
        for(size_t i=0;i<Hweight.size();++i){
            if(HWeight[i] !=invaild){
                prio_queue.push(new Node(HWeight[i]));
            }
        }
        while(prio_queue.size()>1){
            pNode pLeft = prio_queue.top();
            prio_queue.pop();
            
            pNode pRight =prio_queue.top();
            prio_queue.pop();

            pNode pParent = new Node(pLeft->huffWeight + pRight->huffWeight);
            pParent->pLeft = pLeft;
            pParent->pRight = pRight;

            prio_queue.push(pParent);
        }
        pRoot = prio_queue.top();
     }
     //获取根节点的指针
     pNode getRoot(){
         return pRoot;
     }
     //获取根节点的权重(出现的次数)
     unsigned long long getRootWeight(){
         return pRoot->huffWeight.count;
     }
     ~HuffmanTree(){
         Destory(pRoot);
     }
    private:
        void Destory(pNode &proot){
            if(proot){
                Destory(proot->pLeft);
                Destory(proot->pRight);
                delete proot;
                proot=nullptr;
            }
        }
}
