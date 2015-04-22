//LCA正常做法

bool NodePath(TreeNode * root, TreeNode* node, vector<TreeNode*> &path){
	if (root == node){
		return true;
	}
	path.push_back(root);
	bool isExits = false;
	if (root->left){
		isExits = NodePath(root->left, node, path);
	}
	if (!isExits && root->right){
		isExits = NodePath(root->right, node, path);
	}
	if(!isExits){
		path.pop_back();
	}
	return isExits;
}

TreeNode *LCA(TreeNode* root, TreeNode* u, TreeNode* v){
	vector<TreeNode*> path1, path2;
	bool isFound1 = NodePath(root, u, path1);
	bool isFound2 = NodePath(root, v, path2);
	if(!isFound1||!isFound2) //只要一个没找到
		return nullptr;
	int size1 = path1.size();
	int size2 = path2.size();
	TreeNode *node = nullptr;
	for(int i = 0, j = 0; i < size1 && j < size2; ++i,++j){
		if(path1[i] == path2[j])
			node = path1[i];
	}
	return node;
	
}