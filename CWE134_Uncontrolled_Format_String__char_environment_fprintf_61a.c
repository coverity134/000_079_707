/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_fprintf_61a.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fprintf with "%s" as the second argument and data as the third
 *    BadSink : fprintf with data as the second argument
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
char * CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b_badSource(char * data);

void CWE134_Uncontrolled_Format_String__char_environment_fprintf_61_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b_badSource(data);
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);//SLIVER_SINK
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char * CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b_goodG2BSource(char * data);

static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b_goodG2BSource(data);
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);//SLIVER_SINK
}

/* goodB2G uses the BadSource with the GoodSink */
char * CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b_goodB2GSource(char * data);

static void goodB2G()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b_goodB2GSource(data);
    /* FIX: Specify the format disallowing a format string vulnerability */
    fprintf(stdout, "%s\n", data);//SLIVER_SINK
}

void CWE134_Uncontrolled_Format_String__char_environment_fprintf_61_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__char_environment_fprintf_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_environment_fprintf_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
//SLIVER_SOURCE:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b.c:39--->SLIVER_SINK:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61a.c:44 YES
//SLIVER_SOURCE:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b.c:39--->SLIVER_SINK:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61a.c:61 NO
//SLIVER_SOURCE:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b.c:39--->SLIVER_SINK:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61a.c:74 NO
//SLIVER_SOURCE:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b.c:68--->SLIVER_SINK:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61a.c:44 NO
//SLIVER_SOURCE:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b.c:68--->SLIVER_SINK:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61a.c:61 NO
//SLIVER_SOURCE:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61b.c:68--->SLIVER_SINK:CWE134_Uncontrolled_Format_String__char_environment_fprintf_61a.c:74 YES