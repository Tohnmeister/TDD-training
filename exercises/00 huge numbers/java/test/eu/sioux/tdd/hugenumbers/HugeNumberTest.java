package eu.sioux.tdd.hugenumbers;

import org.junit.Test;

import java.util.Calendar;
import java.util.GregorianCalendar;

import static org.junit.Assert.*;

public class HugeNumberTest {
    @Test
    public void testInitialization() throws Exception {
        // No underflow possible on Least-Significant value - exception!
        NumberFormatException caught = null;
        try {
            HugeNumber hn = new HugeNumber(new int[]{1, 1, 0}, new int[]{5, 9, 9}, new int[]{0, 1, 0});
            System.out.println(hn.toString());
        } catch (NumberFormatException e) {
            // We want this!
            caught = e;
            System.out.println(e.toString());
        }

        assertNotNull("Expected an exception during initialization", caught);

        // However, underflow IS possible on non-Least-Significant value if LSV
        // isn't at lower limit!
        caught = null;
        try {
            HugeNumber hn = new HugeNumber(new int[]{1, 1, 0}, new int[]{5, 9, 9}, new int[]{2, 0, 0});
            System.out.println(hn.toString());
        } catch (NumberFormatException e) {
            // We don't want this!
            caught = e;
            System.out.println(e.toString());
        }

        assertNull("Didn't expected an exception during initialization", caught);
    }

    @Test
    public void testRange() throws Exception {
        HugeNumber hn = new HugeNumber(new int[]{1, 1, 0}, new int[]{5, 9, 9}, new int[]{1, 1, 0});

        assertEquals("Range mismatches", (5 * 9 * 10), hn.getRange());
    }

    @Test
    public void testAddition() throws Exception {
        HugeNumber cn = new HugeNumber(new int[]{0, 0}, new int[]{9, 9}, new int[]{0, 0});

        System.out.println(cn);

        int oldVal = cn.toInt().intValue();
        cn.add(10);

        System.out.println(cn);

        assertEquals((oldVal + 10), cn.toInt().intValue());

    }

    @Test
    public void testLoop() throws Exception {
        try {
            long numberDone = 0;
            HugeNumber npn = new HugeNumber(new int[]{1, 0, 0}, new int[]{5, 9, 9}, new int[]{1, 0, 0});
            Long lastResult = null;
            String lastValue = null;

            boolean allOk = true;

            while (allOk && (numberDone < 30)) {
                try {
                    lastValue = npn.toString();
                    lastResult = npn.toInt(); // for now = np

                    if ((numberDone % 1) == 0) {
                        Calendar now = new GregorianCalendar();
                        String dateAndTime = String.format("%04d-%02d-%02d %02d:%02d", now.get(Calendar.YEAR), now
                                .get(Calendar.MONTH) + 1, now.get(Calendar.DAY_OF_MONTH), now.get(Calendar.HOUR_OF_DAY), now
                                .get(Calendar.MINUTE));
                        String progress = String.format("[%d-%d] @ %s: %s", numberDone, lastResult.intValue(), dateAndTime,
                                lastValue);
                        System.out.println(progress);
                    }

                    assertEquals("Value mismatches", numberDone, lastResult.intValue());

                    npn.add(1);
                    numberDone++;
                } catch (Exception e) {
                    allOk = false;
                }
            }

            System.out.println("Last (#" + numberDone + "): " + lastValue);
        } catch (Exception e) {
            // Uh-Oh
        }
    }

}