/**
 *功能:	判断两个操作符的优先级
 *参数:	operator1--操作符1
 *		operator2--操作符2
 *返回:	操作符1优先级大于操作符2	--LEVEL_BIGGER
 *		操作符1优先级小于操作符2	--LEVEL_SMALLER
 *		操作符1优先级等于操作符2	--LEVEL_SAME
 *		操作符1操作符2对比不合法	--LEVEL_INVALID
 *其他:	2014/04/17 By Jim Wen Ver1.0
 *说明:	这里'+'和'-'，'*'和'/'在实际四则运算时的优先顺序
 *		是相同的,所以这里的优先级判定时设置两个操作符级别
 *		列表,一个操作符列表是把另一个操作符级别列表中的相
 *		同级别的操作符的顺序做了颠倒
**/
LEVEL_TYPE CompareLevel(char operator1, char operator2)
{
    char	levelTable1[] = {'#', '(', '+', '-', '*', '/', ')'};
    char	levelTable2[] = {'#', ')', '-', '+', '/', '*', '('};
    int		nTable1Index1, nTable1Index2;
    int		nTable2Index1, nTable2Index2;

    //不合法情况判断
    if ((operator1==')' && operator2=='(') ||
        (operator1=='#' && operator2==')') ||
        (operator1=='(' && operator2=='#'))
    {
        return LEVEL_INVALID;
    }

    //判断相等情况
    if ((operator1=='(' && operator2==')') ||
        (operator1=='#' && operator2=='#'))
    {
        return LEVEL_SAME;
    }

    //判断两个操作符在两个优先级表中的位置
    nTable1Index1 = nTable1Index2 = -1;
    nTable2Index1 = nTable2Index2 = -1;

    while (levelTable1[++nTable1Index1] != operator1);
    while (levelTable1[++nTable1Index2] != operator2);
    while (levelTable2[++nTable2Index1] != operator1);
    while (levelTable2[++nTable2Index2] != operator2);

    //1.判断两个操作符的优先级关系
    //2.'#' < '+', '-' < '*', '/' 
    //3.两个相同的运算符或同级别的运算符('+'和'-'，'*'和'/')
    //对比时应判定为前一个运算符优先级别高,这样才能保证连续
    //两个相同的运算符或同级别的运算符出现时前一个运算符出栈
    //完成一次计算
    if (nTable1Index1-nTable1Index2<0 && nTable2Index1-nTable2Index2<0 ||
        operator1 == '(' ||
        operator2 == '(')
    {
        return LEVEL_SMALLER;
    }
    else
    {
        return LEVEL_BIGGER;
    }
}


/**
 *功能:	输入字符串形式的表达式，计算表达式结果
 *参数:	pExpression		--字符串形式的表达式
 *		pResult			--表达式求解结果
 *返回:	计算成功			--真(表达式合法)
 *		计算不成功		--假
 *其他:	2014/04/17 By Jim Wen Ver1.0
**/
JWArray_BOOL CalcExpression(char *pExpression, double *pResult)
{
    JWArray			*pStackOperator, *pStackNum;
    char			*pCur;
    JWArrayElem		eOp, eNum1, eNum2, eResult;
    JWArray_BOOL	bResult;

    pCur	= pExpression;
    bResult	= JWARRAY_TRUE;

    //创建运算符栈和操作数栈
    pStackOperator	= JWArrayCreate(10, 10);
    pStackNum		= JWArrayCreate(10, 10);

    //初始化操作符栈,入栈'#'表示计算的开始和结束的'#'对应
    JWArrayPush(pStackOperator, (JWArrayElem)'#');

    //遍历算术表达式字符串
    while(pCur[0] != '\0')
    {
        if (JWARRAY_FALSE == IsOperator(pCur[0]))//操作数直接压入操作数栈
        {
            JWArrayPush(pStackNum, (JWArrayElem)atof(pCur));
            MoveToNext(&pCur);
        }
        else
        {
            //获取运算符栈顶元素
            JWArrayGetTop(pStackOperator, &eOp);

            switch (CompareLevel((char)eOp, pCur[0]))
            {
            case LEVEL_INVALID:
                bResult	= JWARRAY_FALSE;					
                break;

            case LEVEL_SMALLER:
                JWArrayPush(pStackOperator, (JWArrayElem)(pCur[0]));//运算符压入运算符栈
                MoveToNext(&pCur);
                break;

            case LEVEL_SAME:
                JWArrayPop(pStackOperator, NULL);					//脱掉括号('('和')'，'#'和'#')
                MoveToNext(&pCur);
                break;

            case LEVEL_BIGGER:
                //出栈操作数和操作符
                if(JWARRAY_FALSE == JWArrayPop(pStackOperator, &eOp) || 
                   JWARRAY_FALSE == JWArrayPop(pStackNum, &eNum2) ||
                   JWARRAY_FALSE == JWArrayPop(pStackNum, &eNum1))
                {
                    //出栈错误(输入不合法时)
                    bResult	= JWARRAY_FALSE;					
                    break;
                }

                //计算出错
                if (JWARRAY_FALSE == Calc((double)eNum1, (char)eOp, (double)eNum2, (double *)&eResult))
                {
                    bResult	= JWARRAY_FALSE;					
                    break;
                }

                JWArrayPush(pStackNum, eResult);

                //注意这里不移动到下一个操作数或运算符，即出栈计算直到能够计算的计算完毕才再移动
                break;
            }
        }

        //操作符比较过程出现非法，跳出循环，返回计算错误
        if (JWARRAY_FALSE == bResult)
        {
            break;
        }
    }

    //如果运算符栈不为空或操作数栈长度不等于1则运算表达式不合法
    if (JWArrayGetLength(pStackOperator) != 0 ||
        JWArrayGetLength(pStackNum) != 1)
    {
        bResult	= JWARRAY_FALSE;
    }
    else
    {
        JWArrayGetTop(pStackNum, (JWArrayElem *)pResult);
    }

    //销毁运算符栈和操作数栈
    JWArrayDestroy(pStackOperator);
    JWArrayDestroy(pStackNum);

    return bResult;
}