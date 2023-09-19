#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode* v_stack[SIZE];

//스택에 노드 추가
void push(TreeNode* p)
{
	if (top < SIZE - 1)
		v_stack[++top] = p;
}

//스택에서 노드 꺼내기
TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = v_stack[top--];
	return p;
}

//중위 순회 
void inorder_iter(TreeNode* root)
{
	if (root == NULL) return;

	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf(" %d", root->data);
		root = root->right;
	}
}

///전위 순회
void preorder_iter(TreeNode* root)
{
	if (root == NULL) return;

	push(root);
	//스택이 비어있지 않은 경우
	while (top >= 0)
	{
		//방문할 노드를 스택에서 pop
		root = pop();
		if (root)
		{
			printf(" %d", root->data);
			//오른쪽 뿌리 노드 push
			push(root->right);
			//왼쪽 뿌리 노드 push
			push(root->left);
		}
	}

}

//후위 순회 
void postorder_iter(TreeNode* root)
{
	if (root == NULL) return;

	//루트 노드 push
	push(root);

	//방문 순서를 저장할 배열 생성
	TreeNode* outputstack[SIZE];
	int i = 0;

	while (top >= 0) {
		root = pop();
		outputstack[i++] = root;
		if (root->left != NULL)
			push(root->left);
		if (root->right != NULL)
			push(root->right);
	}
	for (i = i - 1; i >= 0; i--)
		printf(" %d", outputstack[i]->data);


}

TreeNode n1 = { 4, NULL,NULL };
TreeNode n2 = { 5, NULL,NULL };
TreeNode n3 = { 3, &n1,&n2 };
TreeNode n4 = { 6, NULL,NULL };
TreeNode n5 = { 2, &n3, &n4 };
TreeNode n6 = { 10, NULL,NULL };
TreeNode n7 = { 11, NULL,NULL };
TreeNode n8 = { 9, &n6, &n7 };
TreeNode n9 = { 8, NULL,NULL };
TreeNode n10 = { 7, &n9,&n8 };
TreeNode n11 = { 1, &n5 ,&n10 };
TreeNode* root = &n11;

int main()
{
	printf("<Traversal with Stack>\n");
	printf("1.전위 순회\n");
	preorder_iter(root);
	printf("\n");
	printf("2.중위 순회\n");
	inorder_iter(root);
	printf("\n");
	printf("3.후위 순회\n");
	postorder_iter(root);

}