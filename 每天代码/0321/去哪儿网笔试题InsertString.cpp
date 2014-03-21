#include <iostream>
#include <string>

//��str����С��minLenʱ����strǰ����cʱ���ȵ���minLen��Ȼ�󷵻�
//��str���ȵ��ڻ����minLenʱ��ֱ�ӷ���
//���磺
//InsertString("a", 3, '#');// �����ַ���"##a";
//InsertString("abcd", 3, '#');//�����ַ���"abcd"

std::string InsertString(const std::string &str, int minLen, char c){
    int strLen = str.length();
    if (strLen >= minLen)
        return str;

    int charNum = minLen - strLen;
    std::string rlt(charNum, c);
    rlt.append(str);
    return rlt;
}

int main()
{
    bool test_ok = true;
    if (InsertString("a", 3, '#') != "##a"){
        std::cout << "(a, 3, #)test false!" << std::endl;
        test_ok = false;
    }
    if (InsertString("abcd", 3, '#') != "abcd"){
        std::cout << "(abcd, 3, #)test false!" << std::endl;
        test_ok = false;
    }

    if (test_ok) std::cout << "all test ok!" << std::endl;
    return 0;
}
