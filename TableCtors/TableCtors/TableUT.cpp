#include "stdafx.h"
#include <gtest/gtest.h>
#include "CTable.hpp"
#include "Utils.hpp"
#include <limits>

using namespace defaultVals;
namespace
{
class CTableTests : public testing::Test
{
protected:
   virtual void SetUp()
   {}

   virtual void TearDown()
   {}
};

TEST_F(CTableTests, defCTOR_getSize_DEFAULTSIZE_Expect_DEFAULTSIZE)
{
   CTable* inVal = new CTable();
   int expVal = DEFAULT_IN_TABLE_SIZE;

   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete inVal;
}

TEST_F(CTableTests, defCTOR_setSize_0_Expect_0)
{
   int inSize = ZERO;
   CTable* inVal = new CTable(inSize);
   int expVal = ZERO;

   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete inVal;
}

TEST_F(CTableTests, copyCTOR_size5_Expect_size5)
{
   int inSize = FIVE;
   int expVal = FIVE;
   CTable* sourceVal = new CTable(inSize);

   CTable* inVal = new CTable(*sourceVal);
   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete sourceVal;
   delete inVal;
}

TEST_F(CTableTests, copyCTOR_withAssignCopyOperator_size5_Expect_size5)
{
   int inSize = FIVE;
   int expVal = FIVE;
   CTable* sourceVal = new CTable(inSize);

   CTable* inVal = new CTable();
   *inVal = *sourceVal;

   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete sourceVal;
   delete inVal;
}

TEST_F(CTableTests, setVal_defaultCTORed_3_onIdx_0_Expect_3)
{
   int newVal = 500;
   int idxForNewVal = 0;
   CTable* sourceVal = new CTable();

   int oldVal = sourceVal->getVal(idxForNewVal);
   sourceVal->setVal(idxForNewVal, newVal);
   int rcVal = sourceVal->getVal(idxForNewVal);

   ASSERT_NE(oldVal, rcVal);
   ASSERT_EQ(newVal, rcVal);
   delete sourceVal;
}

TEST_F(CTableTests, getVal_defaultCTORed_3_onIdx_m1_Expect_LimitMin)
{
   int idx = -1;
   CTable* sourceVal = new CTable();

   int rcVal = sourceVal->getVal(idx);

   ASSERT_EQ(std::numeric_limits<int>::min(), rcVal);
   delete sourceVal;
}
}

