
// case 1
template <typename RetType, typename T1, typename T2>
RetType add(const T1 &t1, const T2 &t2)
{
    std::cout << "---------- case 1 ------------" << std::endl;
    return t1 + t2;
};

// case 2
template <typename T1, typename RetType, typename T2>
RetType add(const T1 &t1, const T2 &t2)
{
    std::cout << "---------- case 2 ------------" << std::endl;
    return t1 + t2;
}

// case 3
template <typename RetType = long long, typename T1, typename T2>
RetType add2(const T1 &t1, const T2 &t2)
{
    std::cout << "---------- case 3 ------------" << std::endl;
    return t1 + t2;
}