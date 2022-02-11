#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>

void init(){
    std::srand(std::time(NULL));
}

int main() {
    init();

    std::vector<int> a, b;  // 每次随机生成的两个变量
    std::vector<int> ans, corr_ans, err_id;  // ans:用户输入的答案，corr_ans:正确答案，err_id:错误题目的id
    std::vector<std::string> ss;

    int timeout = 10;  // 每道题目最大时间限制，单位s
    std::vector<int> ttime;  // 每道题用户所用时间
    std::time_t stime, etime; // 每道题起始、终止时间

    int mode = -1;
    std::string smode[3] = {"easy", "medium", "hard"};
    int cnt = 0;
    std::cout << "请选择题目的数量：";
    while (std::cin >> cnt) {
        if (cnt > 0)
            break;
        else
            std::cerr << "请输入正确题目数量！" << std::endl;
    }
    printf("请确定题目难度：\neasy请选择0\nmedium请选择1\nhard请选择2\n");
    while (std::cin >> mode) {
        if (mode < 0 || mode > 2)
            std::cerr << "请选择正确难度！" << std::endl;
        else
            break;
    }

    // printf("您有%d道题目需要解答,难度模式为：%s\n", cnt, smode[mode]);
    std::cout << "您有" << cnt << "道题需要解答, 难度模式为" << smode[mode] << std::endl;

    // printf("开始生成题目中......\n");
    std::cout << "开始生成题目中..." << std::endl;

    int e_num = 0, m_num = 0, h_num = 0;

    // 生成题目个数
    if (mode == 0)  // easy
        e_num = cnt;
    else if (mode == 1) {   // medium
        e_num = std::rand() % cnt;
        // std::cout << e_num << std::endl;
        m_num = cnt - e_num;
    }
    else if (mode == 2) {  // hard
        int tmp = cnt;
        e_num = std::rand() % tmp;
        // std::cout << e_num << std::endl;
        tmp -= e_num;
        m_num = std::rand() % tmp;
        // std::cout << m_num << std::endl;
        h_num = cnt - e_num - m_num;
        // std::cout << h_num << std::endl;
    }
    std::cout << e_num << "道easy题" << std::endl;
    std::cout << m_num << "道medium题" << std::endl;
    std::cout << h_num << "道hard题" << std::endl;

    int i = 0;
    int tmp_ans, _a, _b;
    int t;

    // easy
    for (; i < e_num; ++i) {
        // std::cout << i << std::endl;
        _a = std::rand() % 10;
        _b = std::rand() % 10;
        a.push_back(_a);
        b.push_back(_b);
        printf("%d + %d = ", a[i], b[i]);
        stime = std::time(0);
        std::cin >> tmp_ans;
        etime = std::time(0);
        t = (int)(etime - stime);
        ttime.push_back(t);
        ans.push_back(tmp_ans);
        corr_ans.push_back(_a + _b);
    }

    // medium 
    for (; i < e_num+m_num; ++i) {
        _a = std::rand() % 100;
        _b = std::rand() % 100;
        a.push_back(_a);
        b.push_back(_b);
        printf("%d + %d = ", a[i], b[i]);
        stime = std::time(0);
        std::cin >> tmp_ans;
        etime = std::time(0);
        t = (int)(etime - stime);
        ttime.push_back(t);
        ans.push_back(tmp_ans);
        corr_ans.push_back(_a + _b);
    }

    // hard
    for (; i < e_num+m_num+h_num; ++i) {
        _a = std::rand() % 10;
        _b = std::rand() % 10;
        a.push_back(_a);
        b.push_back(_b);
        printf("%d * %d = ", a[i], b[i]);
        stime = std::time(0);
        std::cin >> tmp_ans;
        etime = std::time(0);
        t = (int)(etime - stime);
        ttime.push_back(t);
        ans.push_back(tmp_ans);
        corr_ans.push_back(_a * _b);
    }

    int num1 = 0, num2 = 0;
    char sign = '+';            // + *
    int totalScore = cnt * 10;  // 总分
    int flag = 0;  
    double totalTime = 0.0;
    double minTime = 999;
    for (int j = 0; j < cnt; ++j) {
        flag = 0;
        if (j == (e_num + m_num))
            sign = '*';
        if (ans[j] != corr_ans[j]) {
            num1++;
            flag = 1;
            totalScore -= 10;
            printf("第%d题(%d %c %d)回答错误, 正确答案是：%d, 您的错误答案是：%d\n", j+1, a[j], sign, b[j], corr_ans[j], ans[j]);
        }

        if (ttime[j] > timeout) {
            num2++;
            if (flag == 0)
                totalScore -= 10;
            printf("第%d题(%d %c %d)回答超时,所用时间为%ds,超时了%ds\n", j+1, a[j], sign, b[j], ttime[j], ttime[j]-timeout);
        }

        totalTime += ttime[j];
        if (ttime[j] < minTime)
            minTime = ttime[j];

    }

    // total score is cnt * 10

    printf("一共%d道题,您答对了%d道,答错了%d道,超时了%d道\n", cnt, cnt-num1, num1, num2);
    printf("总共用时%fs,平均用时%fs,最短用时%fs\n", totalTime, totalTime/(1.0 * cnt), minTime);
    printf("最终得分是：%d\n", totalScore);

    return 0;
}