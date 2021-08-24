#include <QtCore>

QTextStream in(stdin);
QTextStream out(stdout);

QHash<QPair<int, int>, bool> cache;

bool isHappy(int number, int base)
{
    QString nums;
    nums.setNum(number, base);

    if(nums == "1")
        return true;

    QPair<int, int> cacheIndex = QPair<int, int>(number, base);

    if(cache.contains(cacheIndex))
        return cache[cacheIndex];

    int sum = 0;
    foreach(QChar nc, nums) {
        int n = QString(nc).toInt();
        sum += n*n;
    }

    cache[cacheIndex] = isHappy(sum, base);
    return cache[cacheIndex];
}

int main()
{
    int N;
    in >> N;
    in.readLine();

    for(int cas = 1; cas <= N; cas++) {
        QString line = in.readLine();
        QStringList basess = line.split(" ");

        int num = 1;
        bool found = false;
        while(!found) {
            num++;
            found = true;
            foreach(QString bases, basess) {
                if(!isHappy(num, bases.toInt())) {
                    found = false;
                    break;
                }
            }
        }

        out << QString("Case #%1: %2").arg(cas).arg(num) << endl << flush;
    }
    return 0;
}
