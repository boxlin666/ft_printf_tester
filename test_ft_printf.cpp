#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <climits>
#include <string>
#include <fstream>
#include <sstream>

extern "C" int ft_printf(const char *format, ...);

TEST(ft_printf_test, basic)
{
    testing::internal::CaptureStdout();
    ft_printf("Hello, World!\n");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!\n");
}

TEST(ft_printf_test, percent_c)
{
    testing::internal::CaptureStdout();
    ft_printf("%c", 'A');
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(ft_printf_test, percent_s)
{
    testing::internal::CaptureStdout();
    ft_printf("%s", "Hello, World!\n");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!\n");
}

TEST(ft_printf_test, percent_i_base)
{
    testing::internal::CaptureStdout();
    ft_printf("%i", 42);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "42");
}

TEST(ft_printf_test, percent_d_max)
{
    testing::internal::CaptureStdout();
    ft_printf("%d", INT_MAX);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2147483647");
}

TEST(ft_printf_test, percent_d_min)
{
    testing::internal::CaptureStdout();
    ft_printf("%d", INT_MIN);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-2147483648");
}

TEST(ft_printf_test, percent_p)
{
    testing::internal::CaptureStdout();
    void *ptr = (void *)0x12345678;
    ft_printf("%p", ptr);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%p", ptr);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);
}

TEST(ft_printf_test, percent_p_NULL)
{
    testing::internal::CaptureStdout();
    void *empty_pointer = NULL;
    ft_printf("%p", empty_pointer);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%p", empty_pointer);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);
}
TEST(ft_printf_test, percent_u)
{
    testing::internal::CaptureStdout();
    ft_printf("%u", UINT_MAX);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%u", UINT_MAX);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);
}

TEST(ft_printf_test, percent_x)
{
    testing::internal::CaptureStdout();
    ft_printf("%x", INT32_MAX);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%x", INT32_MAX);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);   
}

TEST(ft_printf_test, percent_X)
{
    testing::internal::CaptureStdout();
    ft_printf("%X", INT32_MAX);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%X", INT32_MAX);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);   
}

TEST(ft_printf_test, percent_percent)
{
    testing::internal::CaptureStdout();
    ft_printf("%%");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "%");
}

TEST(ft_printf_test_bonus, sharp_percent_x)
{
    testing::internal::CaptureStdout();
    ft_printf("%#x", INT32_MAX);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%#x", INT32_MAX);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);   
}

TEST(ft_printf_test_bonus, plus_percent_d)
{
    testing::internal::CaptureStdout();
    ft_printf("%+d", 42);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%+d", 42);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);
}

TEST(ft_printf_test_bonus, space_percent_d)
{
    testing::internal::CaptureStdout();
    ft_printf("% d", 42);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("% d", 42);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);
}

TEST(ft_printf_test_bonus, mix)
{
    testing::internal::CaptureStdout();
    ft_printf("%#+d", 255);
    std::string ft_output = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    printf("%#+d", 255);
    std::string std_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(ft_output, std_output);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
