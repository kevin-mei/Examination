观察者模式：

 布告板基类是观察者Observer，里面有updated的方法，三个布告板是子类，需实现update； 需要有一个，update 可以穿三个参数，温度，气压，湿度，  后续可能增加更多的信息，可以预留参数；
 
 
 WeatherData 是subject，这是别人给你的，
 Isubject 需要有Attach  Detach  Noteify,
 WeatherData 继承Isubject，  添加三个布告板子类，在Noteify，
 subject 
 
 
 
 
 
 




### 设计原则：
 4. 为了交互对象之间的松耦合设计而努力