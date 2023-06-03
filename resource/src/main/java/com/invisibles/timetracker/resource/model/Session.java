package com.invisibles.timetracker.resource.model;

import java.sql.Timestamp;
import java.time.LocalDateTime;

import org.springframework.format.annotation.DateTimeFormat;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonIgnore;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import jakarta.persistence.Temporal;
import jakarta.persistence.TemporalType;
import lombok.Data;
import lombok.Getter;
import lombok.ToString;

@Data
@Entity(name = "Session")
@Table(name = "session")
public class Session {
    @Id
    @ToString.Exclude
    @Getter(onMethod_ = {@JsonIgnore})
    @GeneratedValue
    @Column(
            name = "id",
            updatable = false
    )
    private Long id;

    @Column(
            name = "user_id",
            columnDefinition = "TEXT"
    )
    private String userId;
    @Column(
            name = "application_name",
            columnDefinition = "TEXT"
    )
    private String applicationName;

    @Column(
            name = "url",
            columnDefinition = "TEXT"
    )
    private String url;

    @Column(
            name = "title",
            columnDefinition = "TEXT"
    )
    private String title;

    @Temporal(TemporalType.TIMESTAMP)
    @Column(
            name = "time_start",
            columnDefinition = "TIMESTAMP"
    )
    private Timestamp timeStart;
    @Temporal(TemporalType.TIMESTAMP)
    @Column(
            name = "time_end",
            columnDefinition = "TIMESTAMP"
    )
    private Timestamp timeEnd;

}
