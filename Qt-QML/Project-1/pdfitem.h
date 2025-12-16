#pragma once
#include <QQuickPaintedItem>
#include <poppler-qt5.h>
#include <memory>

class PdfItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
    Q_PROPERTY(int pageNum READ pageNum WRITE setPageNum NOTIFY pageNumChanged)
    Q_PROPERTY(int pageCount READ pageCount NOTIFY pageCountChanged)

public:
    explicit PdfItem();
    using QQuickPaintedItem::QQuickPaintedItem;
    void paint(QPainter *painter) override;

    QString filePath() const { return m_filePath; }
    void setFilePath(const QString &path);
    int pageNum() const { return m_pageNum; }
    void setPageNum(int num);
    int pageCount() const;

signals:
    void filePathChanged();
    void pageNumChanged();
    void pageCountChanged();

private:
    QString m_filePath;
    int m_pageNum = 0;
    std::unique_ptr<Poppler::Document> m_doc;
};
