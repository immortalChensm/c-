/**

new��delete��operator���ص����������
������������
1��new����ʱ���ͷ�ʱ���Բ���delete [] �ͷ� new int[2] �ֽڴ�С=4+4=8���ֽ�

�Զ�����
1��new����ʱ�����������������ʱ �ͷ�ʱ������delete [] �ͷţ������ڴ�й¶
�Զ����� new class[2] �ֽڴ�С=class�ֽڴ�С*2+��x86ƽ̨����4���ֽڣ�x64����8���ֽڣ���������ڼ�¼���������Ԫ�ظ�����
                     �ֽڴ�С�������û����������ʱ��=class�ֽڴ�С*2

int *p = new int;//4 Bytes
int *p = new int[2];//8 Bytes
delete p;delete [] p//������

class A{}

A *obj = new A();//1Bytes
A *obj = new A[2]();//2Bytes

delete obj;//��ȷ����Ϊû����������
class B{
    public:
        B(){}
        ~B(){}
}

B *obj = new B[2]();//x86=6Bytes,x64=10Bytes ��������ڼ�¼2
B *obj1 = new B();//1bytes
delete [] obj;//delete obj ����


**/