# 计算器交互

1. 用户可以随机选择生成多少道题目。n>0
2. 用户可以随机选择题目难度。m = 0,1,2
3. 题目数量与难度选择错误会提示用户继续输入。
4. 输出答题平均用时与最短用时。

# 题目难度

1. easy模式：输入0，easy模式下为n道不超过10的加法题。
2. medium模式：输入1，medium模式下，为m道不超过10的加法题和n-m道不超过100的加法题。（m也是随机生成的）
3. hard模式：输入2，hard模式下，为k到不超过10的加法题，m道不超过100的加法题，n-k-m道不超过10的乘法题。（k+m<=n）

# 计分形式

1. 每道题为10分。
2. 每道题限制时长为10s，超过10s直接扣除10分。
3. 做错题目直接扣除10分。
4. 计算错误与超时同时存在，仅扣除10分。

# 流程

请选择题目的数量：**10**
请确定题目难度：
easy请选择0
medium请选择1
hard请选择2
**-1**
请选择正确难度！
**2**
您有10道题需要解答, 难度模式为hard
开始生成题目中...
7道easy题
0道medium题
3道hard题
2 + 8 = 10
6 + 5 = 10
2 + 0 = 2
7 + 0 = 7
4 + 5 = 9
8 + 8 = 6
4 + 1 = 5
8 * 5 = 40
7 * 0 = 1
8 * 1 = 8
第2题(6 + 5)回答错误, 正确答案是：11, 您的错误答案是：10
第4题(7 + 0)回答超时,所用时间为12,超时了2
第6题(8 + 8)回答错误, 正确答案是：16, 您的错误答案是：6
第6题(8 + 8)回答超时,所用时间为12s,超时了2s
第9题(7 * 0)回答错误, 正确答案是：0, 您的错误答案是：1
一共10道题,您答对了7道,答错了3道,超时了2道
总共用时48.000000s,平均用时4.800000s,最短用时2.000000s
最终得分是：60