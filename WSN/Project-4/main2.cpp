/**
 * @file main2.cpp
 * @author your name (you@domain.com)
 * @brief Central place to rename/modify keys, using Qt C++ lib
 * @version 0.1
 * @date 2025-05-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <QCoreApplication>
#include <QVariantMap>
#include <QDebug>
#include <memory>
#include <vector>
#include <QString>

// ---------- Common Data Structure ----------
struct SensorDataItem {
    QString key;
    QVariant value;
};

// ---------- Interface ----------
class ISensorAdapter {
public:
    virtual ~ISensorAdapter() = default;
    virtual QVariantMap getData() const = 0;
};

// ---------- Key Mapper ----------
class KeyMapper {
public:
    void addMapping(const QString& original, const QString& mapped) {
        keyMap[original] = mapped;
    }

    QString mapKey(const QString& original) const {
        return keyMap.contains(original) ? keyMap[original] : original;
    }

    QVariantMap remapKeys(const QVariantMap& input) const {
        QVariantMap result;
        for (auto it = input.begin(); it != input.end(); ++it) {
            result[mapKey(it.key())] = it.value();
        }
        return result;
    }

private:
    QMap<QString, QString> keyMap;
};

// ---------- Adapters ----------
class SensorSettingAdapter : public ISensorAdapter {
public:
    QVariantMap getData() const override {
        return {
            {"samplingRate", 100},
            {"unit", "Celsius"}
        };
    }
};

class SensorCalibrationAdapter : public ISensorAdapter {
public:
    QVariantMap getData() const override {
        return {
            {"offset", 1.5},
            {"scale", 0.98}
        };
    }
};

class SensorHistoryAdapter : public ISensorAdapter {
public:
    QVariantMap getData() const override {
        return {
            {"lastCalibrated", "2025-05-17"},
            {"calibratedBy", "Technician A"}
        };
    }
};

// ---------- Aggregator ----------
class SensorDataAggregator {
public:
    void setAdapters(const std::vector<std::shared_ptr<ISensorAdapter>>& adapters) {
        m_adapters = adapters;
    }

    void setKeyMapper(std::shared_ptr<KeyMapper> mapper) {
        m_keyMapper = std::move(mapper);
    }

    QVariantMap aggregateData() const {
        QVariantMap result;
        for (const auto& adapter : m_adapters) {
            auto data = adapter->getData();
            auto mappedData = m_keyMapper ? m_keyMapper->remapKeys(data) : data;

            for (auto it = mappedData.begin(); it != mappedData.end(); ++it) {
                result.insert(it.key(), it.value());
            }
        }
        return result;
    }

private:
    std::vector<std::shared_ptr<ISensorAdapter>> m_adapters;
    std::shared_ptr<KeyMapper> m_keyMapper;
};

// ---------- Main ----------
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create adapters
    auto settingAdapter = std::make_shared<SensorSettingAdapter>();
    auto calibrationAdapter = std::make_shared<SensorCalibrationAdapter>();
    auto historyAdapter = std::make_shared<SensorHistoryAdapter>();

    // Key mapper setup
    auto keyMapper = std::make_shared<KeyMapper>();
    keyMapper->addMapping("samplingRate", "Sampling Rate");
    keyMapper->addMapping("unit", "Unit");
    keyMapper->addMapping("offset", "Calibration Offset");
    keyMapper->addMapping("scale", "Calibration Scale");
    keyMapper->addMapping("lastCalibrated", "Last Calibrated");
    keyMapper->addMapping("calibratedBy", "Calibrated By");

    // Aggregator setup
    SensorDataAggregator aggregator;
    aggregator.setAdapters({settingAdapter, calibrationAdapter, historyAdapter});
    aggregator.setKeyMapper(keyMapper);

    // Get aggregated data
    QVariantMap data = aggregator.aggregateData();
    for (auto it = data.begin(); it != data.end(); ++it) {
        qDebug() << it.key() << ":" << it.value().toString();
    }

    return 0;
}
