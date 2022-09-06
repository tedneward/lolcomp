package com.tedneward.lolcode

import java.io.File
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFalse
import kotlin.test.assertTrue

class RuntimeTests {
    @Test
    fun variantInitializationGetsTypeRight() {
        fun test(str : String) : Triple<Boolean, Boolean, Boolean> {
            return Triple(Variant.isBoolean(str), Variant.isLong(str), Variant.isDouble(str))
        }

        assertEquals(Triple(false, true, true), test("5"))
        assertEquals(Triple(false, false, true), test("5.0"))
        assertEquals(Triple(false, false, true), test("-15.7"))
        assertEquals(Triple(true, false, false), test("true"))
        assertEquals(Triple(true, false, false), test("TRUE"))
        assertEquals(Triple(true, false, false), test("false"))
        assertEquals(Triple(true, false, false), test("FALSE"))
        assertEquals(Triple(false, false, false), test("This is a boring string"))
    }

    @Test
    fun testVariantBasics() {
        val v = Variant(0)

        assertEquals("0", v.asString())
        assertEquals(0, v.asInt64())
        assertEquals(0.0, v.asDouble())
        assertEquals(false, v.asBoolean())
        assertEquals("[0 (NUMBR)]", v.toString())
    }
    @Test fun testVariantNOOB() {
        val v = Variant()
        assertEquals("[NOOB]", v.toString())

        try { v.asString(); assertTrue(false, "Should never get here") }
        catch (ex : Exception) { assertEquals("CANT CONVER NOOB", ex.message) }

        try { v.asInt64(); assertTrue(false, "Should never get here")  }
        catch (ex : Exception) { assertEquals("CANT CONVER NOOB", ex.message) }

        try { v.asDouble(); assertTrue(false, "Should never get here")  }
        catch (ex : Exception) { assertEquals("CANT CONVER NOOB", ex.message) }

        try { v.asBoolean(); assertTrue(false, "Should never get here")  }
        catch (ex : Exception) { assertEquals("CANT CONVER NOOB", ex.message) }
    }
    @Test fun strings() {
        val v1 = Variant("This is a test")
        assertEquals("This is a test", v1.asString())
    }
    @Test fun testBooleanConversions() {
        assertEquals(true, Variant(1).asBoolean())
        assertEquals(false, Variant(0).asBoolean())
        assertEquals(true, Variant(-1).asBoolean())
    }
    @Test fun mathsConversionRules() { 
        val fiveString = Variant("5")
        val fiveDecimalString = Variant("5.2")

        assertEquals(5, fiveString.asInt64())
        assertEquals(5.0, fiveString.asDouble())
        assertEquals(5, fiveDecimalString.asInt64()) // truncates
        assertEquals(5.2, fiveDecimalString.asDouble())
    }
    @Test fun mathsTests() {
        val one = Variant("WIN")
        val two = Variant(2)
        val three = Variant("3.0")
        val four = Variant("4")

        assertEquals(Variant(3).asInt64(), one.asInt64() + two.asInt64())
        assertEquals(Variant(4).asInt64(), one.asInt64() + three.asInt64())
        assertEquals(Variant(5).asInt64(), one.asInt64() + four.asInt64())

        assertEquals(Variant(3).asDouble(), one.asDouble() + two.asDouble())
        assertEquals(Variant(4).asDouble(), one.asDouble() + three.asDouble())
        assertEquals(Variant(5).asDouble(), one.asDouble() + four.asDouble())
    }
}
