
+Serial.print("data1  =  ");
+Serial.println(data1);
+Serial.print("data2  =  ");
+Serial.println(data2);
+Serial.print("data3  =  ");
+Serial.println(data3);
+if ((data1==HIGH)&&(data2==LOW)&&(data3==HIGH))forward2();
+if ((data1==LOW)&&(data2==HIGH)&&(data3==HIGH))left2();
+if ((data1==HIGH)&&(data2==HIGH)&&(data3==LOW))right2();
+if ((data1==LOW)&&(data2==LOW)&&(data3==HIGH))left2();
+if ((data1==HIGH)&&(data2==LOW)&&(data3==LOW))right2();
+}
+}
+
+ if (value== 'D')
+ {
+  int x = hat();
+  Serial.println(x);
+  distanceF (x);
+  }
+ if (value== 'A')
+ {
+   int x = hat();
+  Serial.println(x);
+  angle (x);
+  }
+if (value== 'Z')
+{
+  
+  delay(5000);
