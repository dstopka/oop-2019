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