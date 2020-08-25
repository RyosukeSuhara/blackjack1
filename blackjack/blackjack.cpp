#include<ctime>
using namespace std;
#include <iostream>

//勝敗を判断する関数
int judgement(int a, int b) {
    if (a <= 21 && b <= 21 && a > b) {
        return 1;
    }
    else if (a <= 21 && b <= 21 && a < b) {
        return 2;
    }
    else if(a > 21 && b <= 21){
        return 2;
    }
    else if (a <= 21 && b > 21) {
        return 1;
    }
    else if (a > 21 && b > 21) {
        return 0;
    }
    else if (a == b) {
        return 0;
    }
        

}

int main()
{
    int player = 0;
    int cpu = 0;
    int playernum = 0;
    const int bj = 21;
    
    srand(time(NULL));

    //乱数でプレイヤーの手札を決める
    player += rand() % 10 + 1;
    player += rand() % 10 + 1;

    //乱数でCPUの手札を決める
    cpu += rand() % 10 + 1;
    cpu += rand() % 10 + 1;

    //山札から引くかどうかを判断させる
    while (player <= bj)
    {
        cout << "あなたの手札は" << player << "です" << endl;
        cout << "もう一枚引きますか？ 1:引く　0:引かない" << endl;
        cin >> playernum;
        if (playernum == 1) {
            player += rand() % 10 + 1;
        }
        else {
            break;
        }
    }

    //CPUの手札が１３以下だったらもう一枚引く
    while (cpu < 14) {
        cpu += rand() % 10 + 1;
    }

    //お互いの手札を公開
    cout << "あなたの手札は" << player << "です" << endl;
    cout << "相手の手札は" << cpu << "です" << endl;

    //関数で判断した勝敗を表示する
    if (judgement(player, cpu) == 1) {
        cout << "あなたの勝ちです！" << endl;
    }
    else if (judgement(player, cpu) == 2) {
        cout << "あなたの負けです！" << endl;
    }
    else if (judgement(player, cpu) == 0) {
        cout << "引き分けです！" << endl;
    }


}

