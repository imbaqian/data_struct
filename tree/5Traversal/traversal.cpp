//二叉树的非递归遍历

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val):val(val),left(NULL),right(NULL){}
};

/*	1.访问结点p，并将结点p入栈；
	2.判断结点p的左儿子是否为空，若为空，
	则取栈顶结点并进行出战操作，并将栈顶结点的右儿子置为当前的结点p，
	若不为空，则将p的左孩子置为当前的结点p；
	3.直到p为NULL并且栈为空，遍历结束。	  
 */
void PreOrderTraversal(TreeNode *root){//根左右
	stack<TreeNode*> st;
	TreeNode *p = root;
	while( p != NULL || !st.empty()){
		while(p!= NULL){
			cout << p->val << " ";
			st.push(p);
			p = p->left;
		}
		if( !st.empty()){
			p = st.top();
			st.pop();
			p=p->right;
		}
	}
}
void InOrderTraversal(TreeNode *root){//左根右
	stack<TreeNode*> st;
	TreeNode *p = root;
	while(p != NULL || !st.empty()){
		while(p != NULL){
			st.push(p);
			p = p->left;
		}
		if( !st.empty()){
			p = st.top();
			cout << p->val << " ";
			st.pop();
			p = p->right;
		}

	}
}


/*后续遍历思路一：
  要保证根结点在左孩子和右孩子访问之后才能访问，因此对已任一结点p，
  先将其入栈，如果p不存在左孩子和右儿子，则可以直接访问它，
  或者p存在左儿子或右儿子，当是其左右儿子已经被访问过了，
  则同样可以直接访问该结点，若非上述两种情况，则将p的右儿子和左儿子
  依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，
  左孩子和右孩子都在根节点前面被访问。
	
 */
void PostOrderTraversal(TreeNode *root){//左右根
	if(root == NULL)
		return;
	stack<TreeNode*> st;
	TreeNode *p = root;
	TreeNode *pre = NULL;
	st.push(p);
	while(!st.empty()){
		p = st.top();
		if( (p->left == NULL && p->right == NULL)||
			(pre != NULL && (p->left == pre || p->right == pre))){
			//如果当前结点是叶子结点，或者儿子结点被访问过
			cout << p->val << " ";
			st.pop();
			pre = p;
		}
		else{
			if(p->right != NULL)
				st.push(p->right);
			if(p->left != NULL)
				st.push(p->left);
		}
	}
}
/*后续遍历方法二：
  对于任一结点p，将其入栈，然后沿其左子树一直往下搜索，知道搜索到没有左儿子的结点，
  此时该结点出现在栈顶，但此时不能将其出栈并访问，因为其右儿子还未被访问，
  所以接下来按相同的规则对其右子树进行相同处理，当访问完其右孩子时，
  该结点又出现在栈顶，只有在第二次出现在栈顶时，才能访问它，
  因此需要多设置一个变量标识该结点是第一次出现在栈顶。
 */
struct sNode{ // 辅助结构，多一个是否第一次访问isFirst
	TreeNode *tnode;
	bool isFirst;
	sNode(TreeNode *p):tnode(p),isFirst(true){}
};
void PostOrderTraversal_2(TreeNode *root){
	stack<sNode*> st;
	TreeNode *p = root;
	
	while( p != NULL || !st.empty()){
		while(p != NULL){
			sNode *btn = new sNode(p);
			st.push(btn);
			p = p->left;
		}
		if(!st.empty()){
			sNode *temp = st.top();
			if(temp->isFirst == true){//第一次访问
				temp->isFirst = false;
				p = temp->tnode->right;
			}
			else{ // 访问完p的右子树，回来了，第二次访问p
				cout << temp->tnode->val << " ";
				st.pop();
			}
		}
	}

}
int main(){
	TreeNode *root; 
	root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(7);
	root->right->left = new TreeNode(14);
	root->right->right = new TreeNode(20);
	PreOrderTraversal(root);
	cout << endl;
	InOrderTraversal(root);
	cout << endl;
	PostOrderTraversal(NULL);
	cout << endl;
	PostOrderTraversal_2(NULL);
	cout << endl;
	return 0;
}
