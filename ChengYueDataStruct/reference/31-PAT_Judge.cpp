#include<cstdio>
#include<algorithm>
#include<vector>

const int INIT = -2;  // ��ʼ�� 
const int NOPASS = -1;  // δͨ������ 
const int MAXID = 10005;  //���ID 
using namespace std;

struct info{
	int id;    // id�� 
	int ques[6];  // ÿ����÷�
	int sum;   // �ܷ� 
	int solved;   // ������� 
};

// ����sort ��������� 
bool cmp(info a,info b){
	if(a.sum != b.sum)
		return a.sum>b.sum;	
	if(a.solved != b.solved)
		return a.solved > b.solved;
	return a.id < b.id;
}


int main(){
	int N;  // ʹ��������
	int K;  // ��������
	int M;  // �ύ���� 
	scanf("%d %d %d",&N,&K,&M);
	vector<info> user(N+1); // ʹ������Ϣ
	int Full[K+1];  // ��¼�����ܷ� ,a[i] ��ʾ��i����ķ���
	for(int i=1;i<=K;i++) 
		scanf("%d",&Full[i]);
	// ��ʼ����Ϣ 
	for(int i=1;i<N+1;i++){
		user[i].id = MAXID;  // ��ʼ������� 
		user[i].sum = 0; 
		user[i].solved = 0;
		for(int j=1;j<K+1;j++) 
			user[i].ques[j] = INIT;
	}
	int use;  // ��ұ�� 
	int question;  // ������ 
	int score;  // �÷� 
	int listSum = 0; // Ӧ�ñ�������� 
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&use,&question,&score);
		// ֻҪͨ�����룬����Ҿ��ܱ���ʾ
		if(score >= 0 && user[use].id == MAXID){
			listSum++;
			user[use].id = use;
		} 
		// �����и�����³ɸ��� 
		if(user[use].ques[question] < score){
			user[use].ques[question] = score;
		}
	}
	for(int i=1;i<N+1;i++)
		for(int j=1;j<K+1;j++){
			// ������ȫ��ȷ������ 
			if(user[i].ques[j] == Full[j])
				user[i].solved++;
			// �����ܷ� 
			if(user[i].ques[j] != NOPASS && user[i].ques[j] != INIT)
				user[i].sum += user[i].ques[j];
		} 
	
	sort(user.begin()+1,user.end(),cmp);
	
	int preSum = user[1].sum;
	int preNum = 1;
	
	for(int i=1;i<=listSum;i++){ 
	    // ������ϴη�����ͬ���������� 
		if(preSum != user[i].sum){ 
			preNum = i;
			preSum = user[i].sum;
		} 
		printf("%d ",preNum);
		printf("%05d %d",user[i].id,user[i].sum);
		for(int j=1;j<K+1;j++){
			// ���ɳ�ʼ��״̬ 
			if(user[i].ques[j] == INIT)
				printf(" -");
			else if(user[i].ques[j] == NOPASS)
				printf(" 0");
			else
				printf(" %d",user[i].ques[j]);
		}
		printf("\n");
	}
	return 0;
}
