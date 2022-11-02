touch 19301151_1.txt 19301151_2.txt 19301151_3.txt 19301151_3.txt 19301151_4.txt
mkdir niamotullahRatul1 niamotullahRatul2
mv 19301151_1.txt 19301151_2.txt 19301151_3.txt niamotullahRatul1
cp niamotullahRatul1/19301151_1.txt niamotullahRatul2/
cp niamotullahRatul1/19301151_2.txt niamotullahRatul2/
mkdir niamotullahRatul3
cp -r niamotullahRatul1/ niamotullahRatul3/
cd niamotullahRatul3
ls -l
cd ..
chmod -R 755 niamotullahRatul3
ls
sudo mv niamotullahRatul3 /root
rm -r *