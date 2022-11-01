using namespace std;

/* 小数点n以下で四捨五入する */
double round_n(double number, int n) {
    number = number * pow(10, n - 1); // 四捨五入したい値を10の(n-1)乗倍する。
    number = round(number);           // 小数点以下を四捨五入する。
    number /= pow(10, n - 1);         // 10の(n-1)乗で割る。
    return number;
}