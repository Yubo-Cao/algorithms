import java.util.HashSet;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class LittleOrphanASCII {

    /*
    Match against work order
    [name] [name] [date]
    5,Door Jammed,02-05-2020
    */
    private static Pattern workOrder = Pattern.compile("(?<id>\\d+),(.*)");

    /*
    Match against work task
    [name] [workId] [partId] [name]
     */
    private static Pattern workTask = Pattern.compile("(?<id>\\d+),(?<workId>\\d+),(?<partId>\\d+),(.*)");

    /*
    Match against part
    [name] [name] [serialNumber]
     */
    private static Pattern part = Pattern.compile("(?<id>\\d+),(.*),(.*)");


    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            var testCaseCount = scan.nextInt();
            for (int j = 0; j < testCaseCount; j++) {
                int W = scan.nextInt(), T = scan.nextInt(), P = scan.nextInt();
                scan.nextLine();
                var workOrderExistsId = IntStream.range(0, W).mapToObj(i -> {
                    var matcher = workOrder.matcher(scan.nextLine());
                    matcher.find();
                    return matcher.group("id").strip();
                }).collect(Collectors.toCollection(HashSet::new));
                var workTaskRaw = IntStream.range(0, T).mapToObj(i -> scan.nextLine()).toList();
                var partExistsId = IntStream.range(0, P).mapToObj(i -> {
                    var matcher = part.matcher(scan.nextLine());
                    matcher.find();
                    return matcher.group("id").strip();
                }).collect(Collectors.toCollection(HashSet::new));

                workTaskRaw.stream().map(workTask::matcher).forEach(matcher -> {
                    matcher.find();
                    var res = new StringBuilder();

                    if (!workOrderExistsId.contains(matcher.group("workId")) && partExistsId.contains(matcher.group("partId")))
                        res.append(String.format("%s MISSING WORK_ORDER %s", matcher.group("id"), matcher.group("workId")));
                    if (!partExistsId.contains(matcher.group("partId")) && workOrderExistsId.contains(matcher.group("workId")))
                        res.append(String.format("%s MISSING PART %s", matcher.group("id"), matcher.group("partId")));
                    if (!workOrderExistsId.contains(matcher.group("workId")) && !partExistsId.contains(matcher.group("partId")))
                        res.append(String.format("%s MISSING WORK_ORDER %s MISSING PART %s", matcher.group("id"), matcher.group("workId"), matcher.group("partId")));

                    if (res.length() > 0)
                        System.out.println(res);
                });
            }
        }
    }

}
