/*#include<queue>
#include<map> 
#include<iostream>
#include<algorithm>
#define MaxSize 64
using namespace std;
priority_queue<int,vector<int>,greater<int> >q; // �������ȶ��У���ǰ���ֵ��С
map<char,int> mapp;  
struct character{
	char ch;   // �ַ� 
	int fre;  // Ƶ�� 
};
struct huffmanTree{
	char ch;  // �ַ� 
	string str;  // ���� 
};


// ����
int bulidTree(int n,character c[]){
	int weight = 0;
	// ��� 
	for(int i=0;i<n;i++)
		q.push((c[i].fre));
	while(q.size()>1){ 
		// ȡ���Ѷ�Ԫ�� 
		int x = q.top();
		// �����Ѷ�Ԫ�� 
		q.pop();
		int y = q.top();
		q.pop();
		// ��� 
		q.push(x+y);
		weight += x+y;  // �õ����볤�� 
		// СȨֵ�᲻�ϱ��� 
	}
	q.pop();
	return weight;
}
bool cmp(huffmanTree a,huffmanTree b){
	return a.str.size() < b.str.size();
}

// �ж��Ƿ�Ϊǰ׺
bool isPrefix(huffmanTree code[],int n){
	// ���ַ������ȴ�С�������� 
	sort(code,code+n,cmp); 
	for(int i=0;i<n;i++){
		string str = code[i].str;
		for(int j=i+1;j<n;j++){ // ����֮��ȫ���ַ�
			// ������ַ����볤�ַ�����ȡ��ͬ������ȣ���Ϊǰ׺ 
			if(code[j].str.substr(0,str.size()) == str)
				return true;
		}
	}
	return false; 
}

void judge(int n,character c[],int weight){
	// ���� WPL 
	huffmanTree code[MaxSize];
	int codelen = 0;
	for(int i=0;i<n;i++){
		cin>>code[i].ch>>code[i].str;
		// ���볤�ȵ��ڱ��볤��*Ƶ���ܺ� 
		codelen += mapp[code[i].ch]*code[i].str.size();  
	}
	if(codelen != weight || isPrefix(code,n))
		cout<<"no"<<endl;
	else
		cout<<"yes"<<endl;
} 

int main(){
	int n;
	int m;
	cin>>n;
	character c[MaxSize];
	for(int i=0;i<n;i++){
		cin>>c[i].ch>>c[i].fre;
		mapp[c[i].ch] = c[i].fre;
	}
	int weight = bulidTree(n,c);
	cin>>m;
	for(int i=0;i<m;i++)
		judge(n,c,weight);
	return 0;
}*/ 
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<map>
#define HeapCapacity 64
#define MinData 0
typedef struct TreeNode *HuffmanTree;
typedef struct Heap *MinHeap;
struct Heap{   // �� 
	HuffmanTree *data;  // ��������� 
	int size; // �ѵĵ�ǰ��С 
};
struct TreeNode{   // �������� 
	int weight;  // Ƶ��
	HuffmanTree left; 
	HuffmanTree right; 
};
using namespace std;

MinHeap createHeap();   // ���� 
HuffmanTree createHuffman();  // ���������� 
void sortHeap(MinHeap H,int i); // ��������С�� 
void adjust(MinHeap H);  // ������ 
MinHeap InitHeap(int n); // ��ʼ���� 
HuffmanTree Delete(MinHeap H); // �ѵ�ɾ�� 
void Insert(MinHeap H,HuffmanTree Huff); // �ѵĲ��� 
HuffmanTree Huffman(MinHeap H);  // ���������Ĺ��� 
int WPL(HuffmanTree Huff,int depth); // ���� HuffmanTree �ı��볤�� 
void PreOrderTraversal(HuffmanTree Huff); // ǰ�����  


map<char,int> mappp;  // �����ַ���Ƶ�ʵ�ӳ���ϵ 

// ���� 
MinHeap createHeap(){
	MinHeap H;
	H = (MinHeap)malloc(sizeof(struct Heap));
	H->data = (HuffmanTree *)malloc(sizeof(struct TreeNode) * HeapCapacity);
	H->size = 0; 
	// �����ڱ�
	HuffmanTree Huff = createHuffman();
	H->data[0] = Huff; 
	return H;
}

// ���������� 
HuffmanTree createHuffman(){
	HuffmanTree Huff;
	Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
	Huff->weight = MinData;   // ��ʼ����Ƶ����С 
	Huff->left = NULL;
	Huff->right = NULL;
	return Huff;
}

// ��������С�� 
void sortHeap(MinHeap H,int i){
	int parent,child;
	HuffmanTree Huff = H->data[i]; // �õ���ǰ�����Ĺ�������
	for(parent = i;parent*2<=H->size;parent = child){
		// ���Ҷ�������С�� 
		child = parent * 2; 
		if((child!=H->size) && (H->data[child+1]->weight < H->data[child]->weight))
			child++;
		// û�и�С���ˣ�����ѭ�� 
		if(Huff->weight <= H->data[child]->weight)
			break;
		// ����Ѷ��ӽ��������
		H->data[parent] = H->data[child]; 
	}
	H->data[parent] = Huff;
} 


// ������ 
void adjust(MinHeap H){
	// �ӵ�һ���к��ӽ��Ľ�㿪ʼ���� 
	for(int i=H->size/2;i>0;i--)
		sortHeap(H,i); 
}

// ��ʼ���� 
MinHeap InitHeap(int n){
	MinHeap H =createHeap();
	HuffmanTree Huff;
	char c;  // ��ʱ�����ַ� 
	int f;  //  ��ʱ����Ƶ�� 
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %d",&c,&f);
		mappp.insert(pair<char,int>(c,f));  // ���ַ���Ƶ�ʵ�ӳ���ϵ���map 
		Huff = createHuffman();
		Huff->weight = f;
		H->data[++H->size] = Huff;
	}
	// ������С�� 
	adjust(H);
	return H;
}

// �ѵ�ɾ�� 
HuffmanTree Delete(MinHeap H){
	int parent,child;
	HuffmanTree T = H->data[1]; // �õ������Ĺ������� 
	HuffmanTree Huff = H->data[H->size--];  // �õ����һ��λ�õĹ������� 
	for(parent = 1;parent*2<=H->size;parent = child){
		// ���Ҷ�������С�� 
		child = parent * 2; 
		if((child!=H->size) && (H->data[child+1]->weight < H->data[child]->weight))
			child++;
		// û�и�С���ˣ�����ѭ�� 
		if(Huff->weight <= H->data[child]->weight)
			break;
		// ����Ѷ��ӽ��������
		H->data[parent] = H->data[child]; 
	}
	H->data[parent] = Huff;
	return T;
} 

// �ѵĲ���
void Insert(MinHeap H,HuffmanTree Huff){
	int i = ++H->size; 
	for(;Huff->weight < H->data[i/2]->weight;i/=2)
		H->data[i] = H->data[i/2];
	H->data[i] = Huff;
} 

// ���������Ĺ��� 
HuffmanTree Huffman(MinHeap H){
	HuffmanTree Huff;
	int times = H->size;
	for(int i=1;i<times;i++){
		Huff = createHuffman();
		Huff->left = Delete(H);  // �Ӷ���ɾ��һ����㣬��Ϊ�� T �����ӽ�� 
		Huff->right = Delete(H);  // �Ӷ���ɾ��һ����㣬��Ϊ�� T �����ӽ�� 
		Huff->weight = Huff->left->weight + Huff->right->weight; // ���¼���Ȩֵ 
		Insert(H,Huff);   // �ټӽ����� 
	}
	Huff = Delete(H);
	return Huff;
} 

// ���� HuffmanTree �ı��볤�� 
int WPL(HuffmanTree Huff,int depth){
	// �����Ҷ��㣬���ر��볤�� 
	if(Huff->left==NULL && Huff->right==NULL)
		return depth*Huff->weight;
	else  // ���򷵻��������ӽ��ı��볤�� 
		return (WPL(Huff->left,depth+1) + WPL(Huff->right,depth+1));
}

// �ύ 
void submit(int n,int codeLen){
	HuffmanTree Huff = createHuffman();
	HuffmanTree pre;
	int counter = 1;
	bool flag = true;
	char ch;
	string code; 
	for(int i=0;i<n;i++){
		getchar();
		pre = Huff; 
		// ����ÿ�� 
		scanf("%c",&ch);
		cin>>code;
		// �������� 
		for(int j=0;j<code.size();j++){
			if(code[j]=='0'){  // �����ǰ����Ϊ 0�����֧ 
				if(pre->left==NULL){   // ��������������ڣ����� 
					pre->left =createHuffman();
					counter++;
				}
				if(pre->weight != 0)
					flag =false;
				pre = pre->left;
			}else if(code[j]=='1'){ // �����ǰ����Ϊ 0�����֧ 
				if(pre->right==NULL){   // ��������������ڣ����� 
					pre->right = createHuffman();
					counter++;
				}
				if(pre->weight != 0)
					flag =false;
				pre = pre->right;
			}
		}
		if(pre->left || pre->right)
			flag = false;
		pre->weight = mappp[ch];   // �� mapp ȡ�����Ƶ��
	}
	if(counter!=2*n-1 || !flag || WPL(Huff,0) != codeLen){ // �����㲻�� 2n-1 ��  ���߱��볤�Ȳ���� 
		printf("No\n");
		return;
	}else{
		printf("Yes\n");
		return;
	}
} 


int main(){
	int n,m;
	scanf("%d",&n);
	// ��ʼ����С�� 
	MinHeap H = InitHeap(n);
	// ��ʼ���������� 
	HuffmanTree Huff = Huffman(H);
	// ����ù��������ı��볤�� 
	int codeLen = WPL(Huff,0); 
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		submit(n,codeLen);
	} 
	return 0;
}
