function(int i,int ����������,int ������)
{
    if(i == n)
                �Ҥ�����ҧ;
                ������Թ
    else
    {
        function(i+1,����������*���������Ǣͧ��Ƿ�� i,������*��������Ƿ�� i);
        function(i+1,����������,������);
    }
}
main()
{
    �Ѻ���
    function(0,1,0);
    printf("%d",min);
}
