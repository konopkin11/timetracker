package com.invisibles.timetracker.resource.model;

import jakarta.persistence.Entity;
import jakarta.persistence.Table;
import lombok.Data;

@Data
@Entity(name = "Note")
@Table(name = "note")
public class Note {

}
