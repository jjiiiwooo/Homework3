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

//���ÿ� ��� �߰�
void push(TreeNode* p)
{
	if (top < SIZE - 1)
		v_stack[++top] = p;
}

//���ÿ��� ��� ������
TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = v_stack[top--];
	return p;
}

//���� ��ȸ 
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

///���� ��ȸ
void preorder_iter(TreeNode* root)
{
	if (root == NULL) return;

	push(root);
	//������ ������� ���� ���
	while (top >= 0)
	{
		//�湮�� ��带 ���ÿ��� pop
		root = pop();
		if (root)
		{
			printf(" %d", root->data);
			//������ �Ѹ� ��� push
			push(root->right);
			//���� �Ѹ� ��� push
			push(root->left);
		}
	}

}

//���� ��ȸ 
void postorder_iter(TreeNode* root)
{
	if (root == NULL) return;

	//��Ʈ ��� push
	push(root);

	//�湮 ������ ������ �迭 ����
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
	printf("1.���� ��ȸ\n");
	preorder_iter(root);
	printf("\n");
	printf("2.���� ��ȸ\n");
	inorder_iter(root);
	printf("\n");
	printf("3.���� ��ȸ\n");
	postorder_iter(root);

}