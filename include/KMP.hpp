//参考知乎的算法介绍用CPP进行实现：https://zhuanlan.zhihu.com/p/83334559
#include <iostream>
#include <vector>

using std::string;
using std::vector;

namespace ns_KMP{
    class KMP
    {
    private:
        #define ASC_NUM 256
        string pat;

    public:
        KMP(string in_pat);
        ~KMP() {};
        vector<vector<int> > dp;   //dp means dynamic programming.

        void print_dp();
        int search(string txt);
    };

    KMP::KMP(string in_pat):pat(in_pat) {
        dp.resize(pat.length(), vector<int>(ASC_NUM));   //初始化dp的二维vector

        int pat_len = pat.length();

        // base case
        dp[0][pat.at(0)] = 1;   
        int shadow_state = 0;    // 影子状态 X 初始为 0
        
        // 当前状态 j 从 1 开始
        for (int j = 1; j < pat_len; j++) {
            for (int c = 0; c < 256; c++) {
                if (pat.at(j) == c) 
                    dp[j][c] = j + 1;
                else 
                    dp[j][c] = dp[shadow_state][c];
            }

            // 更新影子状态
            shadow_state = dp[shadow_state][pat.at(j)];
            
            //add for debug begin
            // print_dp();
            // std::cout << "ss="<< shadow_state << std::endl;
            //add for debug end
        }
    }

    void KMP::print_dp() 
    {
        for(auto i:dp)  {
            for(auto j:i)  std::cout << j << " ";
            std::cout << std::endl;
        }
    }

    int KMP::search(string txt){
        int M = pat.length();
        int N = txt.length();

        // pat 的初始态为 0
        int stat = 0;
        for (int i = 0; i < N; i++) {
            // 计算 pat 的下一个状态
            stat = dp[stat][txt.at(i)];
            // 到达终止态，返回结果
            if (stat == M) return i - M + 1;
        }

        // 没到达终止态，匹配失败
        return -1;
    }

}