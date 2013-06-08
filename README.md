@auther : guohow
@date 14.05.13
Recovery移植汉化：
1, 首先需要recovery的源代码，推荐CWM,如何下载省略。
2, 以CM10.1的源代码为例，移植Nexus7的中文rec
(1) 首先要获取机器相关配置文件
device:
可以从github获取，如果github上没有你的机器型号，那么你需要自己定制：
执行命令，source环境,生成工具，配置变量;
# cd cm10.1
# source build/envsetup.sh
# make otatools
生成了bin下的一系列tool，比如aapt...
之后把终端提示的out目录位置添加到环境变量，如何添加变量以及如何配置linux环境我就不罗嗦了。
切换到工具目录，执行mkvendor.sh
# cd build/tools/device
# ./mkvendor.sh 机器厂商机器型号boot.img所在目录
例如我将boot.img直接放到了tools下：
# ./mkvendor.sh asus grouper boot.img
！如果提示没权限，那么最好切换到主目录执行对整个源码目录赋权
# croot
# cd ..
# sudo chmod 777 -R cm10.1
…..
之后重新执行mkvendor.sh
执行完会发现device目录有了你的设备device
通常这个device不能直接使用，你需要适当修改：
最主要的文件：recovery.fast文件，一般可以通过对比官方的rec进行适当调整，这里就不做过多解释。相信你可以修改好一个能编译rec的device
(2) 开始编译调试
在源码主目录下先执行一遍
# source build/envsetup.sh
以防万一
之后执行lunch：
# lunch cm_device名称-eng
通常格式是这样子的，不排除其他方法，在生成device的同时终端会打印出如何lunch的提示，不再赘述。
lunch完成可以执行rec编译了：
# make -j4 recoveryimage
大约10分钟你可以找到一个初步的recovery了。
各种折腾之后你完成了一个rec的适配，但是你会发现他是E文的，作为一个闲着蛋疼的人，还是要将他汉
化一下证明自己的实力;
3,汉化
首先：获取字库生成脚本以及fonts文件
https://github.com/HyperToxic/CWM_REC_6.0.3.2_CHN.git
字库生成文件在minui下：
graphics.c
chinese.c
chinese.h
这三个是已经修改好的c和头文件;
！你需要手动创建fonts文件夹，放一个.ttf文件，命名为a.ttf
chinese_gen.rb
是ruby下的执行脚本，需要安装ruby运行环境：
#终端下操作：
1.sudo apt-get install ruby1.9.1
2.sudo apt-get install ruby1.9.1-dev
3.sudo apt-get install libmagickwand-dev
4.sudo gem1.9.1 install rmagick
5.sudo apt-get install gperf
fonts自己找字体就是了;
准备工作做好了，开始正是工作，汉化分三步
1,进入recovery主目录，依次打开各个目录下的.c文件，找到print、MENU_ITEM、MENU_HEADERS 字样，适当翻译成汉语。
2，进入minui目录执行：
# ruby *.rb 10 18 18
自动生成相关c文件、头文件、以及字库
将生成的文件复制到源代码里面的minui目录
3, 编译调试
重新编译recovery，刷入，检查各个部分是否汉化完全。