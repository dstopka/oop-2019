#include "TestIncludes.h"
#include "TextWrapper.h"

TEST(TextWrapper, CreateInstance) {
    auto wrapper = TextWrapper{};
}

TEST(TextWrapper, HasColumnsGetter){
    auto wrapper = TextWrapper{};
    EXPECT_EQ(10, wrapper.columns());
}

TEST(TextWrapper, ColumnsSetter){
    auto wrapper = TextWrapper{};
    EXPECT_EQ(4, wrapper.setColumnsNo(4));
}

TEST(TextWrapper, TextGetter){
    auto wrapper = TextWrapper{};
    EXPECT_EQ("ab", wrapper.getText("ab"));
}

TEST(TextWrapper, TextWrap1){
    auto wrapper = TextWrapper{};
    wrapper.setColumnsNo(1);
    wrapper.getText("");
    EXPECT_EQ("", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap2){
    auto wrapper = TextWrapper{};
    wrapper.setColumnsNo(1);
    wrapper.getText("a");
    EXPECT_EQ("a", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap3){
    auto wrapper = TextWrapper{};
    wrapper.setColumnsNo(1);
    wrapper.getText("ab");
    EXPECT_EQ("a\nb", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap4){
    auto wrapper = TextWrapper{};
    wrapper.setColumnsNo(1);
    wrapper.getText("abc");
    EXPECT_EQ("a\nb\nc", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap5){
    auto wrapper = TextWrapper{};
    wrapper.setColumnsNo(2);
    wrapper.getText("abc");
    EXPECT_EQ("ab\nc", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap6){
    auto wrapper = TextWrapper{};
    wrapper.setColumnsNo(2);
    wrapper.getText("ab cd");
    EXPECT_EQ("ab\ncd", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap7){
auto wrapper = TextWrapper{};
wrapper.setColumnsNo(4);
wrapper.getText("ab cde");
EXPECT_EQ("ab\ncde", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap8){
auto wrapper = TextWrapper{};
wrapper.setColumnsNo(4);
wrapper.getText("ab cdefg");
EXPECT_EQ("ab\ncdef\ng", wrapper.wrapText());
}

TEST(TextWrapper, TextWrap9){
auto wrapper = TextWrapper{};
wrapper.setColumnsNo(4);
wrapper.getText("ab cdef ghijk");
EXPECT_EQ("ab\ncdef\nghij\nk", wrapper.wrapText());
}