using namespace std;

/* �����_n�ȉ��Ŏl�̌ܓ����� */
double round_n(double number, int n) {
    number = number * pow(10, n - 1); // �l�̌ܓ��������l��10��(n-1)��{����B
    number = round(number);           // �����_�ȉ����l�̌ܓ�����B
    number /= pow(10, n - 1);         // 10��(n-1)��Ŋ���B
    return number;
}